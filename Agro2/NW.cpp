//========================================================
// Network
//________________________________________________________
#include "NW.h"
//--------------------------------------------------------
NW::NW(QObject *parent)
{
}
//--------------------------------------------------------
void NW::NW_INIT()
{
	GetStatusTimer = new QTimer(this);
	GetStatusTimer->setInterval(CheckStatusInterval);
	SendDataTimer = new QTimer(this);
	SendDataTimer->setInterval(SendDataSendInterval);
	connect(GetStatusTimer, &QTimer::timeout, this, &NW::Get_Status);
	connect(SendDataTimer, &QTimer::timeout, this, &NW::Check_sensor_data);
	GetStatusTimer->start();
	
	hw = new HW();
	hw->HW_INIT();
	connect(this, &NW::NasosOn, hw, &HW::HW_ON);
	connect(this, &NW::NasosOff, hw, &HW::HW_OFF);
	
	
	if (_Debug) qDebug() << "NETWORK CLASS!";
	
}
//--------------------------------------------------------
int NW::Get_Status()
{
	GetStatusTimer->stop();
	QJsonObject json;
	json.insert("number", 1026888929);
	json.insert("status", NasosStatus);
	QJsonDocument jsondoc(json);
	const QByteArray JsonData = jsondoc.toJson();
	
	if (_Debug) qDebug() << "Proverka sostoyaniya - " << JsonData;
	
	QTimer NoInet;
	QNetworkRequest request(QUrl(SMART_URL));
	QByteArray Danniye = LoginPass.toLocal8Bit().toBase64();
	QString HeaderData = "Basic " + Danniye;
	request.setRawHeader("Authorization", HeaderData.toLocal8Bit());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(JsonData.size()));
	QNetworkAccessManager *msg = new QNetworkAccessManager();
	QObject::connect(msg, SIGNAL(finished(QNetworkReply*)), msg, SLOT(deleteLater()));
	
	QEventLoop loop;
	QNetworkReply *reply = msg->post(request, JsonData);
	connect(&NoInet, &QTimer::timeout, &loop, &QEventLoop::quit);
	connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(RequestError(QNetworkReply::NetworkError)));
	NoInet.start(NoInternet);
	loop.exec();
	
	if (reply->error() == QNetworkReply::NoError && NoInet.isActive())
	{
		QByteArray serv_resp = reply->readAll();
		if (_Debug) qDebug() << "Server response - ";
		if (_Debug) qDebug() << serv_resp;
		QJsonDocument JDocResp = QJsonDocument::fromJson(serv_resp);
		if (!JDocResp.isEmpty())
		{
			QJsonObject Jobj = JDocResp.object();
			if (Jobj.contains("status")) 
			{
				if (_Debug) qDebug() << Jobj.value("status").toString();
				if (Jobj.value("status").toString() == "1")
				{
					emit NasosOn();
					NasosStatus = 1;
				}
				else if(Jobj.value("status").toString() == "0")
				{
					emit NasosOff();
					NasosStatus = 0;
				}
			}
			else
			{
				if (_Debug) qDebug() << "Gate status error!";
			}
		}
		else
		{
			if (_Debug)	qDebug() << "Error server response!";
		}
		//===============================
	}
	else
	{
		if (_Debug) qDebug() << "Request Error";
		emit No_Internet_signal();
	}
	
	SendDataTimer->start();
	return 0;
}
//--------------------------------------------------------
void NW::Send_sensor_data(const QByteArray JsonData, int ID)
{
	
	if (_Debug) qDebug() << "Data send - ";
	
	QTimer NoInet;
	QNetworkRequest request(QUrl(SMART_URL));
	QByteArray Danniye = LoginPass.toLocal8Bit().toBase64();
	QString HeaderData = "Basic " + Danniye;
	request.setRawHeader("Authorization", HeaderData.toLocal8Bit());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(JsonData.size()));
	QNetworkAccessManager *msg = new QNetworkAccessManager();
	QObject::connect(msg, SIGNAL(finished(QNetworkReply*)), msg, SLOT(deleteLater()));
	
	QEventLoop loop;
	QNetworkReply *reply = msg->post(request, JsonData);
	connect(&NoInet, &QTimer::timeout, &loop, &QEventLoop::quit);
	connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(RequestError(QNetworkReply::NetworkError)));
	NoInet.start(NoInternet);
	loop.exec();
	
	if (reply->error() == QNetworkReply::NoError && NoInet.isActive())
	{
		QByteArray serv_resp = reply->readAll();
		if (_Debug) qDebug() << "Server response - ";
		if (_Debug) qDebug() << serv_resp;
		Update_sensor_date(ID);
	}
	else
	{
		if (_Debug) qDebug() << "Request Error - " << reply->errorString();
		emit No_Internet_signal();
	}
}
//--------------------------------------------------------
void NW::Check_sensor_data() 
{
	SendDataTimer->stop();
	if (_Debug)	qDebug() << "Search sensor data!";
	{
		QSqlDatabase db;
		db = QSqlDatabase::addDatabase("QPSQL", "SensorData");
		db.setHostName(DbHost);
		db.setDatabaseName(DbName);
		db.setUserName(DbUser);
		db.setPassword(DbPass);
		db.setPort(DbPort);
		db.setConnectOptions("connect_timeout=1");
		if (db.open()) 
		{
			QSqlQuery query(QSqlDatabase::database("SensorData"));
			query.prepare("SELECT * FROM agro_table WHERE is_send = false ORDER BY id LIMIT 1");
			if (!query.exec())
			{
				if (_Debug) qDebug() << query.lastError().text();
			}
			else
			{
				if(query.next())
				{
					QSqlRecord qrec = query.record();
					QJsonObject JObject;
					JObject.insert("hum", qrec.value("hum").toInt());
					JObject.insert("number", qrec.value("num").toInt());
					int ID = qrec.value("id").toInt();
					QJsonDocument jsondoc(JObject);
					QByteArray JsonData = jsondoc.toJson();
					if (_Debug) qDebug() << JsonData;
					Send_sensor_data(JsonData, ID);
				}
				else
				{
					if (_Debug) qDebug() << "No data!";
				}
			}
		}
		else
		{
			if (_Debug) qDebug() << "Can't open database!";
		}
	}
	QSqlDatabase::removeDatabase("SensorData");
	GetStatusTimer->start();
}
//--------------------------------------------------------
void NW::RequestError(QNetworkReply::NetworkError e)
{
	if (_Debug) qDebug() << "Request error - " << e;	
}
//--------------------------------------------------------
void NW::Update_sensor_date(int dataId) 
{
	{
		QSqlDatabase Db = QSqlDatabase::addDatabase("QPSQL", "update");
		Db.setHostName(DbHost);
		Db.setDatabaseName(DbName);
		Db.setUserName(DbUser);
		Db.setPassword(DbPass);
		Db.setPort(DbPort);
		Db.setConnectOptions("connect_timeout=1");
		if (Db.open())
		{
			if (_Debug) qDebug() << "Database open!";
			QSqlQuery query = QSqlQuery(Db);
			query.prepare("UPDATE agro_table SET is_send = (:is_send) WHERE id = (:id)");
			query.bindValue(":is_send", true);
			query.bindValue(":id", dataId);
			if (query.exec())
			{
				if (_Debug) qDebug() << "Sensor data updated";
			}
			else
			{
				if (_Debug) qDebug() << query.lastError().text();
			}
		}
		else
		{
			if (_Debug) qDebug() << "Database not open";
		}
		Db.close();
	}
	QSqlDatabase::removeDatabase("update");
}
//========================================================