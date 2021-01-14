#ifndef PORTCFG_H
#define PORTCFG_H

#include <QDialog>

namespace Ui {
class portcfg;
}

class portcfg : public QDialog
{
    Q_OBJECT
    
public:
    explicit portcfg(QWidget *parent = 0);
    ~portcfg();
    Ui::portcfg *ui;

private slots:
    void on_btn_aceptar_clicked();

    void on_btn_cancelar_clicked();

private:

};

#endif // PORTCFG_H
