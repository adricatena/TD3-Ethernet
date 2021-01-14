/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 29. Sep 11:27:59 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ip;
    QLabel *label_2;
    QLineEdit *port;
    QPushButton *connectButton;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageToSend;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QFormLayout *formLayout_2;
    QRadioButton *rbt1Muestra;
    QRadioButton *rbt5Muestra;
    QRadioButton *rbt10Muestra;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtSen;
    QRadioButton *rbtLuz;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnEnviar;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *lab_maxLuz;
    QSpacerItem *verticalSpacer_2;
    QLabel *lab_midLuz;
    QSpacerItem *verticalSpacer_3;
    QLabel *lab_minLuz;
    QGraphicsView *grfc_Luz;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_grfc_Luz;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *lab_maxSen;
    QSpacerItem *verticalSpacer;
    QLabel *lab_midSen;
    QSpacerItem *verticalSpacer_4;
    QLabel *lab_minSen;
    QGraphicsView *grfc_Sen;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_grfc_Sen;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(505, 681);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icono.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ip = new QLineEdit(centralWidget);
        ip->setObjectName(QString::fromUtf8("ip"));

        horizontalLayout->addWidget(ip);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        port = new QLineEdit(centralWidget);
        port->setObjectName(QString::fromUtf8("port"));

        horizontalLayout->addWidget(port);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout->addWidget(connectButton);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);


        verticalLayout_7->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        messageToSend = new QLineEdit(centralWidget);
        messageToSend->setObjectName(QString::fromUtf8("messageToSend"));

        horizontalLayout_2->addWidget(messageToSend);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rbt1Muestra = new QRadioButton(groupBox);
        rbt1Muestra->setObjectName(QString::fromUtf8("rbt1Muestra"));
        rbt1Muestra->setEnabled(true);
        rbt1Muestra->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rbt1Muestra);

        rbt5Muestra = new QRadioButton(groupBox);
        rbt5Muestra->setObjectName(QString::fromUtf8("rbt5Muestra"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, rbt5Muestra);

        rbt10Muestra = new QRadioButton(groupBox);
        rbt10Muestra->setObjectName(QString::fromUtf8("rbt10Muestra"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, rbt10Muestra);


        formLayout->setLayout(0, QFormLayout::LabelRole, formLayout_2);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_4 = new QFormLayout(groupBox_2);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbtSen = new QRadioButton(groupBox_2);
        rbtSen->setObjectName(QString::fromUtf8("rbtSen"));
        rbtSen->setChecked(true);

        verticalLayout->addWidget(rbtSen);

        rbtLuz = new QRadioButton(groupBox_2);
        rbtLuz->setObjectName(QString::fromUtf8("rbtLuz"));

        verticalLayout->addWidget(rbtLuz);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, verticalLayout);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        btnEnviar = new QPushButton(centralWidget);
        btnEnviar->setObjectName(QString::fromUtf8("btnEnviar"));
        btnEnviar->setEnabled(true);

        horizontalLayout_6->addWidget(btnEnviar);


        verticalLayout_7->addLayout(horizontalLayout_6);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_5);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lab_maxLuz = new QLabel(groupBox_4);
        lab_maxLuz->setObjectName(QString::fromUtf8("lab_maxLuz"));

        verticalLayout_3->addWidget(lab_maxLuz);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        lab_midLuz = new QLabel(groupBox_4);
        lab_midLuz->setObjectName(QString::fromUtf8("lab_midLuz"));

        verticalLayout_3->addWidget(lab_midLuz);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        lab_minLuz = new QLabel(groupBox_4);
        lab_minLuz->setObjectName(QString::fromUtf8("lab_minLuz"));

        verticalLayout_3->addWidget(lab_minLuz);


        horizontalLayout_9->addLayout(verticalLayout_3);

        grfc_Luz = new QGraphicsView(groupBox_4);
        grfc_Luz->setObjectName(QString::fromUtf8("grfc_Luz"));
        grfc_Luz->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grfc_Luz->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout_9->addWidget(grfc_Luz);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        btn_grfc_Luz = new QPushButton(groupBox_4);
        btn_grfc_Luz->setObjectName(QString::fromUtf8("btn_grfc_Luz"));

        horizontalLayout_7->addWidget(btn_grfc_Luz);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_4->addWidget(groupBox_4);


        horizontalLayout_10->addLayout(horizontalLayout_4);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lab_maxSen = new QLabel(groupBox_3);
        lab_maxSen->setObjectName(QString::fromUtf8("lab_maxSen"));

        verticalLayout_2->addWidget(lab_maxSen);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        lab_midSen = new QLabel(groupBox_3);
        lab_midSen->setObjectName(QString::fromUtf8("lab_midSen"));

        verticalLayout_2->addWidget(lab_midSen);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        lab_minSen = new QLabel(groupBox_3);
        lab_minSen->setObjectName(QString::fromUtf8("lab_minSen"));

        verticalLayout_2->addWidget(lab_minSen);


        horizontalLayout_8->addLayout(verticalLayout_2);

        grfc_Sen = new QGraphicsView(groupBox_3);
        grfc_Sen->setObjectName(QString::fromUtf8("grfc_Sen"));

        horizontalLayout_8->addWidget(grfc_Sen);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btn_grfc_Sen = new QPushButton(groupBox_3);
        btn_grfc_Sen->setObjectName(QString::fromUtf8("btn_grfc_Sen"));

        horizontalLayout_5->addWidget(btn_grfc_Sen);


        verticalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout_10->addWidget(groupBox_3);


        verticalLayout_7->addWidget(groupBox_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 505, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Catena - Jaton - Olivera", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Direcci\303\263n IP", 0, QApplication::UnicodeUTF8));
        ip->setText(QApplication::translate("MainWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", ":", 0, QApplication::UnicodeUTF8));
        port->setText(QApplication::translate("MainWindow", "4242", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("MainWindow", "Conectar", 0, QApplication::UnicodeUTF8));
        messageToSend->setText(QString());
        sendButton->setText(QApplication::translate("MainWindow", "Enviar Correci\303\263n", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "N\303\272mero de Muestras", 0, QApplication::UnicodeUTF8));
        rbt1Muestra->setText(QApplication::translate("MainWindow", "1 Muestra", 0, QApplication::UnicodeUTF8));
        rbt5Muestra->setText(QApplication::translate("MainWindow", "5 Muestras", 0, QApplication::UnicodeUTF8));
        rbt10Muestra->setText(QApplication::translate("MainWindow", "10 Muestras", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Variable", 0, QApplication::UnicodeUTF8));
        rbtSen->setText(QApplication::translate("MainWindow", "Se\303\261al", 0, QApplication::UnicodeUTF8));
        rbtLuz->setText(QApplication::translate("MainWindow", "Luz", 0, QApplication::UnicodeUTF8));
        btnEnviar->setText(QApplication::translate("MainWindow", "Enviar", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Gr\303\241ficas", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Luz", 0, QApplication::UnicodeUTF8));
        lab_maxLuz->setText(QApplication::translate("MainWindow", "150", 0, QApplication::UnicodeUTF8));
        lab_midLuz->setText(QApplication::translate("MainWindow", "75", 0, QApplication::UnicodeUTF8));
        lab_minLuz->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btn_grfc_Luz->setText(QApplication::translate("MainWindow", "Limpiar Gr\303\241fica", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Se\303\261al", 0, QApplication::UnicodeUTF8));
        lab_maxSen->setText(QApplication::translate("MainWindow", "400", 0, QApplication::UnicodeUTF8));
        lab_midSen->setText(QApplication::translate("MainWindow", "200", 0, QApplication::UnicodeUTF8));
        lab_minSen->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btn_grfc_Sen->setText(QApplication::translate("MainWindow", "Limpiar Gr\303\241fica", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
