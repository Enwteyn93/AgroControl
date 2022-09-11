//========================================================
// Hardware 
//________________________________________________________
#include <wiringPi.h>
#include <QObject>
#include <QDebug>
#include "ProjectDef.h"
//--------------------------------------------------------
class HW : public QObject
{
	Q_OBJECT
public :
	explicit HW(QObject *parent = 0);
	
public slots :
	void HW_ON();
	void HW_INIT();
	void HW_OFF();


signals :

private:

	
};
//========================================================