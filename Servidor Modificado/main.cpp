/*************************************************************************\
  * KClient - A Toy Server in Qt
  *
  * Author : Manohar Kuse (mpkuse@ust.hk)
  * Date   : 26th Mar, 2014
  * Webpage : http://kusemanohar.wordpress.com/2014/03/26/qt-network-programming/
\*************************************************************************/

#include <QtGui/QApplication>
#include "ethernet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ethernet w;
    w.show();
    
    return a.exec();
}
