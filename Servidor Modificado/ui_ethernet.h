/********************************************************************************
** Form generated from reading UI file 'ethernet.ui'
**
** Created: Thu 29. Sep 11:41:33 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETHERNET_H
#define UI_ETHERNET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ethernet
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *port;
    QPushButton *startServer;
    QLabel *label_3;
    QLabel *statusLabel;
    QGroupBox *groupBox_2;
    QPushButton *btn_conectar;
    QPushButton *btn_desconectar;
    QLabel *label;
    QLabel *lab_estado;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *lab_val_act_sen;
    QGraphicsView *grfc_Sen;
    QPushButton *btn_grfc_Sen;
    QLabel *lab_maxSen;
    QLabel *lab_midSen;
    QLabel *label_9;
    QGroupBox *groupBox_4;
    QLabel *label_13;
    QLabel *lab_val_act_luz;
    QPushButton *btn_grfc_Luz;
    QGraphicsView *grfc_Luz;
    QLabel *lab_maxLuz;
    QLabel *lab_midLuz;
    QLabel *label_10;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Ethernet)
    {
        if (Ethernet->objectName().isEmpty())
            Ethernet->setObjectName(QString::fromUtf8("Ethernet"));
        Ethernet->resize(473, 343);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icono.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Ethernet->setWindowIcon(icon);
        centralWidget = new QWidget(Ethernet);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 231, 81));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 41, 17));
        port = new QLineEdit(groupBox);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(50, 20, 61, 21));
        startServer = new QPushButton(groupBox);
        startServer->setObjectName(QString::fromUtf8("startServer"));
        startServer->setGeometry(QRect(120, 20, 101, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 46, 13));
        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(50, 50, 161, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 0, 231, 81));
        btn_conectar = new QPushButton(groupBox_2);
        btn_conectar->setObjectName(QString::fromUtf8("btn_conectar"));
        btn_conectar->setGeometry(QRect(20, 20, 75, 23));
        btn_desconectar = new QPushButton(groupBox_2);
        btn_desconectar->setObjectName(QString::fromUtf8("btn_desconectar"));
        btn_desconectar->setGeometry(QRect(130, 20, 75, 23));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 46, 13));
        lab_estado = new QLabel(groupBox_2);
        lab_estado->setObjectName(QString::fromUtf8("lab_estado"));
        lab_estado->setGeometry(QRect(50, 50, 171, 16));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 80, 231, 221));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 71, 16));
        lab_val_act_sen = new QLabel(groupBox_3);
        lab_val_act_sen->setObjectName(QString::fromUtf8("lab_val_act_sen"));
        lab_val_act_sen->setGeometry(QRect(80, 20, 91, 16));
        grfc_Sen = new QGraphicsView(groupBox_3);
        grfc_Sen->setObjectName(QString::fromUtf8("grfc_Sen"));
        grfc_Sen->setGeometry(QRect(30, 40, 191, 141));
        btn_grfc_Sen = new QPushButton(groupBox_3);
        btn_grfc_Sen->setObjectName(QString::fromUtf8("btn_grfc_Sen"));
        btn_grfc_Sen->setGeometry(QRect(40, 190, 151, 23));
        lab_maxSen = new QLabel(groupBox_3);
        lab_maxSen->setObjectName(QString::fromUtf8("lab_maxSen"));
        lab_maxSen->setGeometry(QRect(10, 40, 21, 16));
        lab_midSen = new QLabel(groupBox_3);
        lab_midSen->setObjectName(QString::fromUtf8("lab_midSen"));
        lab_midSen->setGeometry(QRect(10, 110, 21, 16));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 170, 16, 16));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(240, 80, 231, 221));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 20, 71, 16));
        lab_val_act_luz = new QLabel(groupBox_4);
        lab_val_act_luz->setObjectName(QString::fromUtf8("lab_val_act_luz"));
        lab_val_act_luz->setGeometry(QRect(80, 20, 91, 16));
        btn_grfc_Luz = new QPushButton(groupBox_4);
        btn_grfc_Luz->setObjectName(QString::fromUtf8("btn_grfc_Luz"));
        btn_grfc_Luz->setGeometry(QRect(50, 190, 131, 21));
        grfc_Luz = new QGraphicsView(groupBox_4);
        grfc_Luz->setObjectName(QString::fromUtf8("grfc_Luz"));
        grfc_Luz->setGeometry(QRect(30, 40, 191, 141));
        lab_maxLuz = new QLabel(groupBox_4);
        lab_maxLuz->setObjectName(QString::fromUtf8("lab_maxLuz"));
        lab_maxLuz->setGeometry(QRect(10, 40, 31, 16));
        lab_midLuz = new QLabel(groupBox_4);
        lab_midLuz->setObjectName(QString::fromUtf8("lab_midLuz"));
        lab_midLuz->setGeometry(QRect(10, 110, 31, 16));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 170, 16, 16));
        Ethernet->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Ethernet);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 473, 21));
        Ethernet->setMenuBar(menuBar);
        statusBar = new QStatusBar(Ethernet);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Ethernet->setStatusBar(statusBar);

        retranslateUi(Ethernet);

        QMetaObject::connectSlotsByName(Ethernet);
    } // setupUi

    void retranslateUi(QMainWindow *Ethernet)
    {
        Ethernet->setWindowTitle(QApplication::translate("Ethernet", "Catena - Jaton - Olivera", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Ethernet", "Conexi\303\263n Ethernet", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Ethernet", "Puerto:", 0, QApplication::UnicodeUTF8));
        startServer->setText(QApplication::translate("Ethernet", "Arrancar Servidor", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Ethernet", "Estado:", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Ethernet", "Conexi\303\263n Serie", 0, QApplication::UnicodeUTF8));
        btn_conectar->setText(QApplication::translate("Ethernet", "Conectar", 0, QApplication::UnicodeUTF8));
        btn_desconectar->setText(QApplication::translate("Ethernet", "Desconectar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Ethernet", "Estado:", 0, QApplication::UnicodeUTF8));
        lab_estado->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Ethernet", "Se\303\261al", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Ethernet", "Valor Actual:", 0, QApplication::UnicodeUTF8));
        lab_val_act_sen->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        btn_grfc_Sen->setText(QApplication::translate("Ethernet", "Limpiar Gr\303\241fica", 0, QApplication::UnicodeUTF8));
        lab_maxSen->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        lab_midSen->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Ethernet", "0", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Ethernet", "Luz", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Ethernet", "Valor Actual:", 0, QApplication::UnicodeUTF8));
        lab_val_act_luz->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        btn_grfc_Luz->setText(QApplication::translate("Ethernet", "Limpiar Gr\303\241fica", 0, QApplication::UnicodeUTF8));
        lab_maxLuz->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        lab_midLuz->setText(QApplication::translate("Ethernet", "-", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Ethernet", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Ethernet: public Ui_Ethernet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETHERNET_H
