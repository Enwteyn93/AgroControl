#include <QCoreApplication>
#include "NW.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	NW nw;
	nw.NW_INIT();
    
    return a.exec();
}
