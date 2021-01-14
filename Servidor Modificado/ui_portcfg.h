/********************************************************************************
** Form generated from reading UI file 'portcfg.ui'
**
** Created: Wed 2. Sep 19:00:29 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTCFG_H
#define UI_PORTCFG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_portcfg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cmb_puertos;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_aceptar;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_cancelar;

    void setupUi(QDialog *portcfg)
    {
        if (portcfg->objectName().isEmpty())
            portcfg->setObjectName(QString::fromUtf8("portcfg"));
        portcfg->resize(217, 81);
        gridLayout = new QGridLayout(portcfg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(portcfg);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cmb_puertos = new QComboBox(portcfg);
        cmb_puertos->setObjectName(QString::fromUtf8("cmb_puertos"));

        horizontalLayout_2->addWidget(cmb_puertos);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_aceptar = new QPushButton(portcfg);
        btn_aceptar->setObjectName(QString::fromUtf8("btn_aceptar"));

        horizontalLayout->addWidget(btn_aceptar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_cancelar = new QPushButton(portcfg);
        btn_cancelar->setObjectName(QString::fromUtf8("btn_cancelar"));

        horizontalLayout->addWidget(btn_cancelar);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(portcfg);

        QMetaObject::connectSlotsByName(portcfg);
    } // setupUi

    void retranslateUi(QDialog *portcfg)
    {
        portcfg->setWindowTitle(QApplication::translate("portcfg", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("portcfg", "Puerto:", 0, QApplication::UnicodeUTF8));
        btn_aceptar->setText(QApplication::translate("portcfg", "Aceptar", 0, QApplication::UnicodeUTF8));
        btn_cancelar->setText(QApplication::translate("portcfg", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class portcfg: public Ui_portcfg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTCFG_H
