/*************************************************************************\
  * Servidor CGR
  *
  * Author : Cabrera Dardo, Gomez Agustin, Roldan Gonzalo
  * Date   : 03th Sep, 2015
  * Company: UTN-FRP (Argentina)
\*************************************************************************/

#include "ethernet.h"
#include "ui_ethernet.h"

#include "portcfg.h"
#include "ui_portcfg.h"

#include <qextserialport.h>
#include <QextSerialEnumerator.h>

#include <QTimer>

#include <QFile>
#include <QTextStream>
#include <QDebug>

Ethernet::Ethernet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ethernet)
{
    ui->setupUi(this);
    this->setFixedSize(473,343);

    //*********************Ethernet****************************************
    // set : acceptTheConnection() will be called whenever there is a new connection

    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptTheConnection()));

    //*********************Puerto Serie****************************************

    puertoSerie = new QextSerialPort();
    puertoSerie->setBaudRate(BAUD9600);
    puertoSerie->setDataBits(DATA_8);
    puertoSerie->setFlowControl(FLOW_OFF);
    puertoSerie->setParity(PAR_NONE);
    puertoSerie->setStopBits(STOP_1);

    connect(puertoSerie,
            SIGNAL(readyRead()),
            this,
            SLOT(DatosRecibidos()));

    //******************Variables a utilizar**************************************
    DatosSen.clear();
    DatosLuz.clear();
    serialPos = 0;
    flagLUZ=false;
    flagSEN=false;
    SenActual=0;
    LuzActual=0;
    SenActualFloat=0;
    LuzActualFloat=0;
    maxSen=150;
    maxLuz=700;
    ui->lab_maxLuz->setText(QString::number(maxLuz));
    ui->lab_midLuz->setText(QString::number(maxLuz/2));
    ui->lab_maxSen->setText(QString::number(maxSen));
    ui->lab_midSen->setText(QString::number(maxSen/2));
}

Ethernet::~Ethernet()
{
    delete ui;
    disconnect(puertoSerie, SIGNAL(readyRead()),
                    this, SLOT(DatosRecibidos()));
        if (puertoSerie->isOpen())
            puertoSerie->close();
        delete puertoSerie;

        delete ui;
        DatosSen.clear();
        DatosLuz.clear();

}


// This fucnction will be called when the button (in the ui) called "startServer" is clicked
void Ethernet::on_startServer_clicked()
{
    // Retrive port number from the user-interface (ui)
    QString portNum = ui->port->text();

    // Instruction to start listening for incoming connection.
    bool status = tcpServer.listen(QHostAddress::Any, portNum.toUShort() );

    // Check, if the server did start correctly or not
    if( status == true )
    {
        QMessageBox::information(this,"Servidor establecido", QString("Servidor escuchando puerto: ")+portNum );
        ui->statusLabel->setText( QString("Escuchando puerto #")+portNum );
    }
    else
    {
        QMessageBox::critical(this, "Servidor no establecido", tcpServer.errorString() );
    }
}


// This function is called whenever we have an incoming connection
void Ethernet::acceptTheConnection()
{
    // In the label (in the ui) print that there in an in-comming connection
    ui->statusLabel->setText("Conexión con cliente establecida");

    // Accept and establish the connection. Note that, the data-transfer happens with `connectionSoc` and not with `tcpServer`
    // `tcpServer` only waits and listens to new connections
    connectionSoc = tcpServer.nextPendingConnection();

    // Set : respondToConnection() will be called whenever the data (coming from client) is available
    connect(connectionSoc, SIGNAL(readyRead()), this, SLOT(respondToConnection()) );

    // Set : connectionAboutToClose() will be called whenever the connection is close by the client
    connect(connectionSoc, SIGNAL(disconnected()), this, SLOT(connectionAboutToClose()));

}


// Will be called whenever the data (coming from client) is available
void Ethernet::respondToConnection()
{
    // Declare a byte array (this is how it is done with Qt)
    QByteArray buf;

    // Read the incoming data. Here 200 is the maximum length
    buf = connectionSoc->read(200);

    // Convert this data to QString. Note that QString is the class which holds strings in Qt
    QString bufString = QString(buf);

    /*// Convert this string to upper case
    bufString = bufString.toUpper();

    // Respond to the client. Note that string.toUtf8() is used to convert string to QByteArray
    connectionSoc->write(bufString.toUtf8());*/
    if(bufString=="Sen")
    {
        if(puertoSerie->isOpen())
        {
            puertoSerie->write(bufString.toUpper().toUtf8());
            flagSEN=true;
        }
        else
        QMessageBox::information(this,"Error", "Conectar Puerto Serie");
    }
    if(bufString=="Luz")
    {
        if(puertoSerie->isOpen())
        {
            flagLUZ=true;
            puertoSerie->write(bufString.toUpper().toUtf8());
        }
        else
        QMessageBox::information(this,"Error", "Conectar Puerto Serie");
    }
}


// Will be called whenever the connection is close by the client
void Ethernet::connectionAboutToClose()
{
    // Set this text into the label
    ui->statusLabel->setText("Conexión cerrada por el cliente");

    // Close the connection (Say bye)
    connectionSoc->close();
}


void Ethernet::on_btn_conectar_clicked()
{
    portcfg cfg(this);
    if (puertoSerie->isOpen())
        puertoSerie->close();
    QList<QextPortInfo> puertos =
            QextSerialEnumerator::getPorts();
    foreach( QextPortInfo unPuerto, puertos )
    {
        cfg.ui->cmb_puertos->addItem(unPuerto.portName);
    }

    if(cfg.exec())
    {
       puertoSerie->setPortName(cfg.ui->cmb_puertos->currentText());
       puertoSerie->open(QIODevice::ReadWrite);
    }
    if(puertoSerie->isOpen())
      ui->lab_estado->setText("Conectado");
    else
      ui->lab_estado->setText("Desconectado");
}


void Ethernet::on_btn_desconectar_clicked()
{
    puertoSerie->close();
    if(puertoSerie->isOpen())
      ui->lab_estado->setText("Conectado");
    else
      ui->lab_estado->setText("Desconectado");
}


//******************************Validacion de dato****************************************************
bool Ethernet::pkgValido(unsigned char *d)
{
    bool Ok_1, Ok_2;

    if(flagSEN==true)
    {
        Ok_1 = d[0] == 'S' && d[1]=='E'&& d[2]=='N'; //si los primeros 3 digitos dicen SEN
        Ok_2 = 'N' == d[sizeof(SerialData) - 1] && 'E' == d[sizeof(SerialData) - 2] && 'S' == d[sizeof(SerialData) - 3]; //si los 3 ultimos dicen SEN
    }
    else if(flagLUZ==true)
    {
        Ok_1 = d[0] == 'L' && d[1]=='U'&& d[2]=='Z'; //si los primeros 3 digitos dicen LUZ
        Ok_2 = 'Z' == d[sizeof(SerialData) - 1] && 'U' == d[sizeof(SerialData) - 2] && 'L' == d[sizeof(SerialData) - 3]; //si los 3 ultimos dicen LUZ
    }
    else
    {
       Ok_1=false;
       Ok_2=false;
    }
    return (Ok_1 && Ok_2);
}


//*****************Procesamineto dato recibido****************************************************
void Ethernet::DatosRecibidos(){
    unsigned int i;
    int bytesReady;
    bytesReady = puertoSerie->bytesAvailable();
    if((serialPos + bytesReady) < SERIALBUFSIZE)
    {
       puertoSerie->read((char *)&serialBuff[serialPos], bytesReady);
       serialPos += bytesReady;
    }
    while(serialPos >= sizeof(SerialData))
    {
        if(pkgValido(serialBuff))
        {
            //SEÑAL
            if(flagSEN==true)
            {
                DatosSen.append(((SerialData *)serialBuff)->DatoH);
                DatosSen.append(((SerialData *)serialBuff)->DatoL);

                //Convierto a un valor equivalente
                SenActual=((unsigned int)DatosSen.value(DatosSen.size()-2)<<8) | ((unsigned int)DatosSen.value(DatosSen.size()-1));
                SenActualFloat=(float)SenActual/2.046;
                ui->lab_val_act_sen->setText(QString::number(SenActualFloat));

                //Guardo en archivo de texto
                //Open the file for writing, and set the text stream to write, to the file.
                QFile archivo("Registro Servidor.txt");
                archivo.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                QTextStream textoparaarchivo(&archivo);
                archivo.atEnd();
                textoparaarchivo << "Amplitud:  " << QString::number(SenActualFloat) << endl;
                archivo.close();

                ///////////////////////////ENVIAR EL DATO POR ETHERNET!!!///////////////////////////
                connectionSoc->write(QString::number(SenActualFloat).toUtf8());

                //Graficar Señal
                grafSen.push_back(SenActualFloat);
                QGraphicsScene * grafica = new QGraphicsScene();
                QGraphicsLineItem * ejeX;
                QGraphicsLineItem * ejeY;
                QPen trazo;
                unsigned int contadorT;
                if(grafSen.size() != 0)
                {
                for(contadorT=1; contadorT < grafSen.size(); contadorT++)
                {
                   grafica->addLine(contadorT-1, -grafSen[contadorT-1], contadorT, -grafSen[contadorT]);
                }
                ejeX = new QGraphicsLineItem(0, 0, grafSen.size()-1, 0);
                ejeY = new QGraphicsLineItem(0, 0, 0, -maxSen);
                trazo.setStyle(Qt::DashLine);
                trazo.setColor(Qt::darkBlue);
                ejeX->setPen(trazo);
                ejeY->setPen(trazo);
                grafica->addItem(ejeX);
                grafica->addItem(ejeY);
                ui->grfc_Sen->setScene(grafica);
                ui->grfc_Sen->fitInView(grafica->sceneRect());
                }

                flagSEN=false;
                puertoSerie->readAll();
            }

            //LUZ
            if(flagLUZ==true)
            {
                DatosLuz.append(((SerialData *)serialBuff)->DatoH);
                DatosLuz.append(((SerialData *)serialBuff)->DatoL);

                //Convierto a un valor equivalente
                LuzActual=((unsigned int)DatosLuz.value(DatosLuz.size()-2)<<8) | ((unsigned int)DatosLuz.value(DatosLuz.size()-1));
                if((float)LuzActual>921)
                {
                    LuzActualFloat=115*(5-(float)LuzActual);
                }
                else
                {
                    LuzActualFloat=205.357*(4.78304-(float)LuzActual);
                }
                LuzActualFloat=(float)LuzActual;
                ui->lab_val_act_luz->setText(QString::number(LuzActualFloat));

                //Guardo en archivo de texto
                //Open the file for writing, and set the text stream to write, to the file.
                QFile archivo("Registro Servidor.txt");
                archivo.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                QTextStream textoparaarchivo(&archivo);
                archivo.atEnd();
                textoparaarchivo << "L:  " << QString::number(LuzActualFloat) << " lux" << endl;
                archivo.close();

                ///////////////////////////ENVIAR EL DATO POR ETHERNET!!!///////////////////////////
                connectionSoc->write(QString::number(LuzActualFloat).toUtf8());

                //Graficar Luz
                grafLuz.push_back(LuzActualFloat);
                QGraphicsScene * grafica = new QGraphicsScene();
                QGraphicsLineItem * ejeX;
                QGraphicsLineItem * ejeY;
                QPen trazo;
                unsigned int contadorL;
                if(grafLuz.size() != 0)
                {
                for(contadorL=1; contadorL < grafLuz.size(); contadorL++)
                {
                   grafica->addLine(contadorL-1, -grafLuz[contadorL-1], contadorL, -grafLuz[contadorL]);
                }
                ejeX = new QGraphicsLineItem(0, 0, grafLuz.size()-1, 0);
                ejeY = new QGraphicsLineItem(0, 0, 0, -maxLuz);
                trazo.setStyle(Qt::DashLine);
                trazo.setColor(Qt::darkBlue);
                ejeX->setPen(trazo);
                ejeY->setPen(trazo);
                grafica->addItem(ejeX);
                grafica->addItem(ejeY);
                ui->grfc_Luz->setScene(grafica);
                ui->grfc_Luz->fitInView(grafica->sceneRect());
                }

                flagLUZ=false;
                puertoSerie->readAll();
            }

            // Quitamos los valores que ya se procesaron.
            for(i = 0; i < SERIALBUFSIZE - sizeof(SerialData); i++)
                serialBuff[i] = serialBuff[i + sizeof(SerialData)];
            serialPos -= sizeof(SerialData);
        }
        else
        {
            for(i = 0; i < SERIALBUFSIZE - 1; i++)
                serialBuff[i] = serialBuff[i + 1];
            serialPos --;
        }
    }
}


void Ethernet::on_btn_grfc_Sen_clicked()
{
    grafSen.clear();
    QGraphicsScene * grafica = new QGraphicsScene();
    QGraphicsLineItem * ejeX;
    QPen trazo;
    ejeX = new QGraphicsLineItem(0, 0, 0, 0);
    ejeX->setPen(trazo);
    grafica->addItem(ejeX);
    ui->grfc_Sen->setScene(grafica);
}


void Ethernet::on_btn_grfc_Luz_clicked()
{
    grafLuz.clear();
    QGraphicsScene * grafica = new QGraphicsScene();
    QGraphicsLineItem * ejeX;
    QPen trazo;
    ejeX = new QGraphicsLineItem(0, 0, 0, 0);
    ejeX->setPen(trazo);
    grafica->addItem(ejeX);
    ui->grfc_Luz->setScene(grafica);
}
