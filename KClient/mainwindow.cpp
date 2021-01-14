/*************************************************************************\
  * KClient - A Toy Client in Qt
  *
  * Author : Manohar Kuse (mpkuse@ust.hk)
  * Date   : 26th Mar, 2014
  * Webpage : http://kusemanohar.wordpress.com/2014/03/26/qt-network-programming/
\*************************************************************************/




#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ip->setText("192.168.1.10");
    ui->port->setText("10");
   // this->setFixedSize(531,557);

    // connectionInit() to be called whenever the connection is estabished
    connect(&tcpSocket,SIGNAL(connected()), this, SLOT(connectionInit()));

    // handleError( ); is called if an error occurs when connecting to the server
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(handleError(QAbstractSocket::SocketError)));

    // dataArrived(); is called when the data has arrived from the server
    connect(&tcpSocket,SIGNAL(readyRead()),this, SLOT(dataArrived()));

    //Aca inicializo los contadores de pedidos de luz y temperatura
    contSenTx=0;
    contLuzTx=0;
    contSenRx=0;
    contLuzRx=0;
    Senal=0;
    Luz=0;
    maxSen=150;
    maxLuz=400;
    ui->lab_maxLuz->setText(QString::number(maxLuz));
    ui->lab_midLuz->setText(QString::number(maxLuz/2));
    ui->lab_maxSen->setText(QString::number(maxSen));
    ui->lab_midSen->setText(QString::number(maxSen/2));


}

MainWindow::~MainWindow()
{
    delete ui;
}


// This function is called when you click the "connect" button in the ui (user-interface)
void MainWindow::on_connectButton_clicked()
{
    // Read the IP address from the text field in the UI (user-interface)
    QHostAddress addr( ui->ip->text() );

    // Attempt to connect to server
    // Note : For simplicity we are not doing a DNS lookup of the IP address. But in real application you need
    //        to do a DNS lookup before attempting to connect. Please search on google "Qt DNS lookup" to
    //        understand how to do a DNS lookup
    tcpSocket.connectToHost(addr, ui->port->text().toUShort()  );

}


// This function is called when the connection has been established successfully with the server stated.
void MainWindow::connectionInit()
{
    // Pop-up to notify you the success
    QMessageBox::information(this,"Conectado", "Conexión establecida");
}


// This function is called if there is an error (or disruption) in the connection
void MainWindow::handleError(QAbstractSocket::SocketError err)
{
    // Pop-up to notify an error. tcpSocket.errorString() automatically gets an error message (in english).
    QMessageBox::critical(this,"Error", tcpSocket.errorString());

    // Formally close the connection
    tcpSocket.close();
}


// This function is called when the data is fully arrived from the server to the client
void MainWindow::dataArrived()
{
    // Read the data that we receive
    QByteArray buf = tcpSocket.read(100); //maximum read 100 bytes

    // Show this data in the textBrowser in the UI (user-interface)
    ui->textBrowser->append(QString("Server >> ") +buf); //put this data into the text browser

    if(contSenRx||contLuzRx)//Si espera datos de luz y señal
    {
        if(contSenRx)//si espera de señal
        {
  //          if(buf.at(buf.begin())=='T')//REVISAR SI HAY QUE CONVERTIR A QSTRING U OTRA COSA//si es la señal
  //          {
  //              buf.remove(buf.begin());
                Senal = QString::QString(buf).toFloat();///PUEDE FALLAR
                contSenRx--;

                ui->textBrowser->append(QString("Señal >> ") + QString::number(Senal)); //put this data into the text browser
                //////////////////////////////////////////////
                //ACA TENGO QUE GUARDAR LOS DATOS EN EL ARCHIVO Y GRAFICARLOS
                //////////////////////////////////////////////
                grafSen.push_back(Senal);
                QGraphicsScene * grafica = new QGraphicsScene();
                QGraphicsLineItem * ejeX,* ejeY, * ejeX2;
                QPen trazo;
                unsigned int contadorT;
                if(grafSen.size() != 0)
                {
                for(contadorT=1; contadorT < grafSen.size(); contadorT++)
                {
                   grafica->addLine(contadorT-1, -grafSen[contadorT-1], contadorT, -grafSen[contadorT]);
                }


                ejeX = new QGraphicsLineItem(0, 0, grafSen.size()-1, 0);
                ejeX2 = new QGraphicsLineItem(0, -maxSen/2, grafSen.size()-1, -maxSen/2);
                ejeY = new QGraphicsLineItem(0, 0, 0, -maxSen);
                trazo.setStyle(Qt::DashLine);
                trazo.setColor(Qt::darkBlue);
                ejeX->setPen(trazo);
                ejeY->setPen(trazo);
                grafica->addItem(ejeX);
                grafica->addItem(ejeX2);
                grafica->addItem(ejeY);//PROBAR//////////////////////////////////////////////
                ui->grfc_Sen->setScene(grafica);
                ui->grfc_Sen->fitInView(grafica->sceneRect());
                }
                //Guardo en archivo de texto
                //Open the file for writing, and set the text stream to write, to the file.
                QFile archivo("RegistroCliente.txt");
                archivo.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                QTextStream textoparaarchivo(&archivo);
                archivo.atEnd();
                textoparaarchivo << "Amplitud:  " << QString::number(Senal) << endl;
                archivo.close();


   //         }
        }
        if(contLuzRx)//si espera de luz
        {
 //           if(buf.at(buf.begin())=='L')//REVISAR SI HAY QUE CONVERTIR A QSTRING U OTRA COSA//si es de luz
 //            {
 //               buf=buf.remove(buf.begin());
                Luz = QString::QString(buf).toFloat();///PUEDE FALLAR
                contLuzRx--;
                ui->textBrowser->append(QString("Luz >> ") + QString::number(Luz)); //put this data into the text browser
                //////////////////////////////////////////////
                //ACA TENGO QUE GUARDAR LOS DATOS EN EL ARCHIVO Y GRAFICARLOS
                //////////////////////////////////////////////

                //Graficar Luz
                grafLuz.push_back(Luz);
                QGraphicsScene * grafica = new QGraphicsScene();
                QGraphicsLineItem * ejeX,* ejeY, * ejeX2;
                QPen trazo;
                unsigned int contadorL;
                if(grafLuz.size() != 0)
                {
                for(contadorL=1; contadorL < grafLuz.size(); contadorL++)
                {
                   grafica->addLine(contadorL-1, -grafLuz[contadorL-1], contadorL, -grafLuz[contadorL]);
                }


                ejeX = new QGraphicsLineItem(0, 0, grafLuz.size()-1, 0);
                ejeX2 = new QGraphicsLineItem(0, -maxLuz/2, grafLuz.size()-1, -maxLuz/2);

                ejeY = new QGraphicsLineItem(0,0,0,-maxLuz);
                trazo.setStyle(Qt::DashLine);
                trazo.setColor(Qt::darkBlue);
                ejeX->setPen(trazo);
                ejeY->setPen(trazo);
                grafica->addItem(ejeX);
                grafica->addItem(ejeY);

                ui->grfc_Luz->setScene(grafica);
                ui->grfc_Luz->fitInView(grafica->sceneRect());
                }
                //Guardo en archivo de texto
                //Open the file for writing, and set the text stream to write, to the file.
                QFile archivo("RegistroCliente.txt");
                archivo.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
                QTextStream textoparaarchivo(&archivo);
                archivo.atEnd();
                textoparaarchivo << "L:  " << QString::number(Luz) << " lux" << endl;
                archivo.close();

 //           }

        }
        if(contSenRx!=0 || contLuzRx!=0)
        on_btnEnviar_clicked();
    }
}


// This function is called whenever, we click the send button in the UI
void MainWindow::on_sendButton_clicked()
{
    // check if the connection is open. ie, if we are connected to a server
    if( !tcpSocket.isOpen() )
    {
        QMessageBox::critical(this, "No conectado al servidor", "No conectado al servidor");
        return;
    }

    // Retrive the text that is written in the UI. The input area where we are supposed to write our message
    QString str = ui->messageToSend->text();

    // Send this data to the server. str.ToUtf8() is done to convert QStrint to QByteArray.
    // Never mind if you don't understand this clearly. Just remember this conversion is required if you want to send
    // the data
    tcpSocket.write(str.toUtf8());

    // Set this same data into the textBrower.
    // Note : 2 strings can be concatenated with a "+"
    ui->textBrowser->append(QString("ME >> ")+str);

    // Clear the sending input box
    ui->messageToSend->clear();
}

void MainWindow::on_btnEnviar_clicked()
{
     QString str;
    // check if the connection is open. ie, if we are connected to a server
    if( !tcpSocket.isOpen() )
    {
        QMessageBox::critical(this, "No conectado al servidor", "No conectado al servidor");
        return;
    }


    if(ui->btnEnviar->isEnabled())
    {

    //ahora desactivo el boton hasta que se termine la comunicacion
    ui->btnEnviar->setDisabled(true);

    //Ahora me fijo que enviar segun los radio button elegidos
    if(ui->rbtSen->isChecked())
    {
    if(ui->rbt1Muestra->isChecked())
    {
        contSenTx=10;
        contSenRx=10;
    }
    else if(ui->rbt5Muestra->isChecked())
    {
        contSenTx=50;
        contSenRx=50;
    }
    else if(ui->rbt10Muestra->isChecked())
    {
        contSenTx=100;
        contSenRx=100;
    }
    }
    else if(ui->rbtLuz->isChecked())
    {
    if(ui->rbt1Muestra->isChecked())
    {
        contLuzTx=10;
        contLuzRx=10;
    }
    else if(ui->rbt5Muestra->isChecked())
    {
        contLuzTx=50;
        contLuzRx=50;
    }
    else if(ui->rbt10Muestra->isChecked())
    {
        contLuzTx=100;
        contLuzRx=100;
    }
    }
    }

    if((contSenTx!=contSenRx) ||(contLuzTx!=contLuzRx))
    {
        contSenTx=0;
        contSenRx=0;
        contLuzTx=0;
        contLuzRx=0;
        QMessageBox::critical(this, "Error", "No se pudo concretar la comunicación");
    }
    else if(contSenTx)
    {
        str = "Sen";
        contSenTx--;
    }
    else if(contLuzTx)
    {
        str = "Luz";
        contLuzTx--;
    }



    if(! str.isEmpty())
    {
        // Send this data to the server. str.ToUtf8() is done to convert QStrint to QByteArray.
    // Never mind if you don't understand this clearly. Just remember this conversion is required if you want to send
    // the data
    tcpSocket.write(str.toUtf8());

    // Set this same data into the textBrower.
    // Note : 2 strings can be concatenated with a "+"
    ui->textBrowser->append(QString("ME >> ")+str);

    // Clear the sending input box
    ui->messageToSend->clear();
    }


    //activo el boton cuando termino de enviar y recibir datos
    if((contLuzTx==0 && contSenTx==0))
        ui->btnEnviar->setEnabled(true);
}

void MainWindow::on_btn_grfc_Sen_clicked()
{
    grafSen.clear();
    QGraphicsScene * grafica = new QGraphicsScene();
    QGraphicsLineItem * ejeX, * ejeX2, *ejeY;
    QPen trazo;
    ejeX = new QGraphicsLineItem(0, 0,1, 0);
    ejeX2= new QGraphicsLineItem(0, -maxSen/2, 1, -maxSen/2);
    ejeY = new QGraphicsLineItem(0, 0, 0, -maxSen);
    trazo.setStyle(Qt::DashLine);
    trazo.setColor(Qt::darkBlue);
    ejeX->setPen(trazo);
    ejeX2->setPen(trazo);
    ejeY->setPen(trazo);
    grafica->addItem(ejeX);
    grafica->addItem(ejeX2);
    grafica->addItem(ejeY);
    ui->grfc_Sen->setScene(grafica);
    ui->grfc_Sen->fitInView(grafica->sceneRect());
}

void MainWindow::on_btn_grfc_Luz_clicked()
{
    grafLuz.clear();
    QGraphicsScene * grafica = new QGraphicsScene();
    QGraphicsLineItem * ejeX, * ejeX2, *ejeY;
    QPen trazo;
    ejeX = new QGraphicsLineItem(0, 0, 1, 0);
    ejeX2= new QGraphicsLineItem(0, -maxLuz/2, 1, -maxLuz/2);
    ejeY = new QGraphicsLineItem(0, 0, 0, -maxLuz);
    trazo.setStyle(Qt::DashLine);
    trazo.setColor(Qt::darkBlue);
    ejeX->setPen(trazo);
    ejeX2->setPen(trazo);
    ejeY->setPen(trazo);
    grafica->addItem(ejeX);
    grafica->addItem(ejeX2);
    grafica->addItem(ejeY);
    ui->grfc_Luz->setScene(grafica);
    ui->grfc_Luz->fitInView(grafica->sceneRect());
}
