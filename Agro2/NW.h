//========================================================
// 
//________________________________________________________
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QHttpMultiPart>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHttpPart>
#include <QUrlQuery>
#include <qurl.h>

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>

#include "ProjectDef.h"
#include "HW.h"

#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QEventLoop>
//--------------------------------------------------------
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
//--------------------------------------------------------
class NW : public QObject
{
	Q_OBJECT
public :
	explicit NW(QObject *parent = 0);
public slots :
	void NW_INIT();
	int Get_Status();
	void Send_sensor_data(const QByteArray, int ID);
	void RequestError(const QNetworkReply::NetworkError);
	void Check_sensor_data();
	void Update_sensor_date(int dataId);

signals:
	void No_Internet_signal();
	void NasosOn();
	void NasosOff();

private:
	QString LoginPass = "rich_fields:HeXBhRrOMOyMvHEp";
	QTimer *GetStatusTimer;
	QTimer *SendDataTimer;
	int NasosStatus = 0;
	HW *hw;
	
};
//--------------------------------------------------------
//========================================================