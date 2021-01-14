#include "portcfg.h"
#include "ui_portcfg.h"

portcfg::portcfg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::portcfg)
{
    ui->setupUi(this);
}

portcfg::~portcfg()
{
    delete ui;
}

void portcfg::on_btn_aceptar_clicked()
{
    accept();
}

void portcfg::on_btn_cancelar_clicked()
{
    close();
}
