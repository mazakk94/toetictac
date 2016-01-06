#include "toetictac.h"

QTcpSocket *clientSock;
QTcpSocket *lastClientConnectedToServ; // przerobic to na tablice klientow-socketow
QTcpServer *serv;

void DropBasket::newClientConnected() {
	lastClientConnectedToServ = serv->nextPendingConnection();
	connect(lastClientConnectedToServ, &QTcpSocket::readyRead, this, &DropBasket::readFromClient);

	ui.pushButton->setText("Odebrano klienta");
}

void DropBasket::startClient() {

	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &DropBasket::readFromServ);
	clientSock->connectToHost(ui.lineEdit->text(), ui.spinBox->value());


	ui.fJoinToServ->setText("Klient utworzony");
}

void DropBasket::readFromServ() {
	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);
	ui.textEdit->append(str);
}

void DropBasket::readFromClient() {
	QByteArray arr = lastClientConnectedToServ->readAll();
	QString str = QString::fromUtf8(arr);
	ui.textEdit->append(str);
}

void DropBasket::startServer() {

	serv = new QTcpServer(this);
	connect(serv, &QTcpServer::newConnection, this, &DropBasket::newClientConnected);
	serv->listen(QHostAddress::Any, 1111);

	ui.pushButton->setText("Serwer utworzony");
}

void DropBasket::clientSend() {
	clientSock->write(ui.fClientMsg->text().toUtf8());
}

void DropBasket::serverSend() {
	lastClientConnectedToServ->write(ui.fServerMsg->text().toUtf8());
}

DropBasket::DropBasket(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(startServer()));
	QObject::connect(ui.fJoinToServ, SIGNAL(clicked()), this, SLOT(startClient()));
	QObject::connect(ui.fClientSend, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.fServerSend, SIGNAL(clicked()), this, SLOT(serverSend()));
}

DropBasket::~DropBasket()
{

}
