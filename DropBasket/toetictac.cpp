#include "toetictac.h"

QTcpSocket *clientSock;
QTcpSocket *lastClientConnectedToServ; // przerobic to na tablice klientow-socketow
QTcpServer *serv;

void Toetictac::newClientConnected() {
	lastClientConnectedToServ = serv->nextPendingConnection();
	connect(lastClientConnectedToServ, &QTcpSocket::readyRead, this, &Toetictac::readFromClient);

	ui.pushButton->setText("Odebrano klienta");
}

void Toetictac::startClient() {

	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &Toetictac::readFromServ);
	clientSock->connectToHost(ui.lineEdit->text(), ui.spinBox->value());


	ui.fJoinToServ->setText("Klient utworzony");
}

void Toetictac::readFromServ() {
	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);
	ui.textEdit->append(str);
}

void Toetictac::readFromClient() {
	QByteArray arr = lastClientConnectedToServ->readAll();
	QString str = QString::fromUtf8(arr);
	ui.textEdit->append(str);
}

void Toetictac::startServer() {

	serv = new QTcpServer(this);
	connect(serv, &QTcpServer::newConnection, this, &Toetictac::newClientConnected);
	serv->listen(QHostAddress::Any, 1111);

	ui.pushButton->setText("Serwer utworzony");
}

void Toetictac::clientSend() {
	clientSock->write(ui.fClientMsg->text().toUtf8());
}

void Toetictac::serverSend() {
	lastClientConnectedToServ->write(ui.fServerMsg->text().toUtf8());
}

Toetictac::Toetictac(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(startServer()));
	QObject::connect(ui.fJoinToServ, SIGNAL(clicked()), this, SLOT(startClient()));
	QObject::connect(ui.fClientSend, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.fServerSend, SIGNAL(clicked()), this, SLOT(serverSend()));
}

Toetictac::~Toetictac()
{

}
