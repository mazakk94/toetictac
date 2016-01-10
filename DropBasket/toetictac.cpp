#include "toetictac.h"
#include <string>
#include <codecvt>

using namespace std;
QTcpSocket *clientSock;
vector<QTcpSocket*> clients; // przerobic to na tablice klientow-socketow
vector<int> clientsTeams;
QTcpServer *serv;
QByteArray isTeam1 = "0";

int numOfTeam1 = 0;
int numOfTeam2 = 0;
bool whichTurn = 0; // 0 - gracz 1
					// 1 - gracz 2

/*
	CZÊŒÆ SERWERA
*/

void Toetictac::newClientConnected() {
	QTcpSocket* newClient = serv->nextPendingConnection();
	clients.push_back(newClient);
	connect(newClient, &QTcpSocket::readyRead, this, &Toetictac::readFromClient);

	ui.pushButton->setText("Odebrano klienta");
}


void Toetictac::startServer() {

	serv = new QTcpServer(this);
	connect(serv, &QTcpServer::newConnection, this, &Toetictac::newClientConnected);
	serv->listen(QHostAddress::Any, 1111);

	ui.pushButton->setText("Serwer utworzony");
}


void Toetictac::readFromClient() {
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i]->bytesAvailable() != 0) {
			QByteArray arr = clients[i]->readAll();
			QString clientID = arr.mid(0, 1);
			if ((whichTurn == 0 && clientID == "1") || (whichTurn == 1 && clientID == "2")){
				QString info("Gracz numer ");

				if (clientID == "1")
					whichTurn = 1; //czas na druzyne 2
				else
					whichTurn = 0; //czas na druzyne 1

				QString info2(": ");
				QString msg(info + clientID + info2 + arr.mid(1, arr.size()));
				ui.textEdit->append(msg);
				break;
			} 
			//ui.textEdit->append(arr);
			//QByteArray arr2 = arr;
			//QString str(QString::fromUtf8(arr));
			//QString str = arr;
			//QStringRef clientID(str, 0, 1);
			
		}
	}
}






void Toetictac::serverSend() {
	for (int i = 0; i < clients.size(); i++) {
		//string msg = isTeam1 + ui.fServerMsg->text().toUtf8()
		clients[i]->write(ui.fServerMsg->text().toUtf8());
	}
}

void Toetictac::voteForButton(){
	//TODO
}

/*
	CZÊŒÆ KLIENTA
*/


void Toetictac::startClient() {
	
	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &Toetictac::readFromServ);
	clientSock->connectToHost(ui.lineEdit->text(), ui.spinBox->value());
	QString text = "Twoj team: " + isTeam1;

	ui.fJoinToServ->setText(text);
}

void Toetictac::readFromServ() {
	
	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);
	ui.textEdit->append(str);
}


void Toetictac::clientSend() {
	QString msg((QString::fromUtf8(isTeam1)) + ui.fClientMsg->text().toUtf8());
	//ui.textEdit->append(msg);
	//QByteArray msgbyte((const char*)(msg.utf16()), msg.size() * 2);
	QByteArray msgbyte = msg.toUtf8();
	//QByteArray msgbyte = (QByteArray) msg;
	clientSock->write(msgbyte);
}

void Toetictac::jointEam1(){
	isTeam1 = "1";
	numOfTeam1++;
	ui.numOfPlayers1->setText(QString::number(numOfTeam1));
	playerJoint();
}

void Toetictac::jointEam2(){
	isTeam1 = "2";
	numOfTeam2++;
	ui.numOfPlayers2->setText(QString::number(numOfTeam2));
	playerJoint();
}

void Toetictac::playerJoint(){
	ui.fJoinToServ->setEnabled(true);
	ui.bTeam1->setEnabled(false);
	ui.bTeam2->setEnabled(false);
}


Toetictac::Toetictac(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(startServer()));
	QObject::connect(ui.fJoinToServ, SIGNAL(clicked()), this, SLOT(startClient()));
	QObject::connect(ui.fClientSend, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.fServerSend, SIGNAL(clicked()), this, SLOT(serverSend()));
	QObject::connect(ui.bTeam1, SIGNAL(clicked()), this, SLOT(jointEam1()));
	QObject::connect(ui.bTeam2, SIGNAL(clicked()), this, SLOT(jointEam2()));
}

Toetictac::~Toetictac()
{

}
