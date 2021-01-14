/*************************************************************************\
  * KClient - A Toy Client in Qt
  *
  * Author : Manohar Kuse (mpkuse@ust.hk)
  * Date   : 26th Mar, 2014
  * Webpage : http://kusemanohar.wordpress.com/2014/03/26/qt-network-programming/
\*************************************************************************/




#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>

#include <QMessageBox>
//para los graficos
#include <ctime>
#include <cstdlib>
#include <QGraphicsLineItem>
#include <QFont>
//para archivos
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <algorithm>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    QString aux;
    QFile archivo;
    QTextStream textoparaarchivo;
    ~MainWindow();

private slots:
    // This function is called whenever, we click the send button in the UI
    void on_sendButton_clicked();

    // This function is called when you click the "connect" button in the ui (user-interface)
    void on_connectButton_clicked();

    // This function is called when the connection has been established successfully with the server stated.
    void connectionInit();

    // This function is called if there is an error (or disruption) in the connection
    void handleError(QAbstractSocket::SocketError err);

    // This function is called when the data is fully arrived from the server to the client
    void dataArrived();

    void on_btnEnviar_clicked();

    void on_btn_grfc_Sen_clicked();

    void on_btn_grfc_Luz_clicked();

private:
    Ui::MainWindow *ui;

    // Variable (socket) to hold the client connection data
    QTcpSocket tcpSocket;
    // Variable contadora de cantidad de datos solicidos tanto de temperatura como de luz
    float Senal;
    float Luz;
    int contSenTx;
    int contLuzTx;
    int contSenRx;
    int contLuzRx;
    //**************************Graficas**************************************
    std::vector<float> grafSen;
    std::vector<float> grafLuz;
    float maxSen;
    float maxLuz;
};

#endif // MAINWINDOW_H
