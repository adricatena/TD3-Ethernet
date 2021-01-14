#ifndef ETHERNET_H
#define ETHERNET_H

#include <QMainWindow>
#include <qextserialport.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <ctime>
#include <cstdlib>
#include <QGraphicsLineItem>
#include <QFont>

#include <QMessageBox>

#include "paquete.h"

#define SERIALBUFSIZE 1024

namespace Ui {
class Ethernet;
}

class Ethernet : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Ethernet(QWidget *parent = 0);
    ~Ethernet();
    QextSerialPort * puertoSerie;
    // QTimer * reloj;
    // QVector <SerialData> vector;//puede que no sirva por eso lo comento
    bool pkgValido(unsigned char *d);
    bool flagLUZ;
    bool flagSEN;
    QString aux;
    QFile archivo;
    QTextStream textoparaarchivo;
    
private slots:
    //*********************Ethernet****************************************
    // Called automatically when "startServer" button is clicked
    void on_startServer_clicked();

    // Called automatically when a client attempts to connect
    void acceptTheConnection();

    // Called automatically when data sent by a client is fully available to the server
    void respondToConnection();

    // Called automatically when client has closed the connection
    void connectionAboutToClose();

    //*********************Puerto Serie****************************************
    void on_btn_conectar_clicked();

    void on_btn_desconectar_clicked();


    void on_btn_grfc_Sen_clicked();

    void on_btn_grfc_Luz_clicked();

public slots:
    void DatosRecibidos();

private:
    Ui::Ethernet *ui;

    //*********************Ethernet****************************************
    // Variable(socket) to store listening tcpserver
    QTcpServer tcpServer;

    // Variable(socket) to store newly established connection with the client
    QTcpSocket * connectionSoc;

    //*********************Puerto Serie****************************************
    unsigned int serialPos;
    unsigned char serialBuff[SERIALBUFSIZE];

    //*************************Variables*********************
    QVector <unsigned char> DatosLuz;
    QVector <unsigned char> DatosSen;
    unsigned int SenActual;
    unsigned int LuzActual;
    float SenActualFloat;
    float LuzActualFloat;
    float maxSen;
    float maxLuz;

     //**************************Graficas**************************************
     std::vector<int> grafSen;
     std::vector<int> grafLuz;
};

#endif // ETHERNET_H
