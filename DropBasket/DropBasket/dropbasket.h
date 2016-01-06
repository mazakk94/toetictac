#ifndef DROPBASKET_H
#define DROPBASKET_H

#include <QtWidgets/QMainWindow>
#include "ui_dropbasket.h"
#include <QWidget>
#include <QtNetwork>

class DropBasket : public QMainWindow
{
	Q_OBJECT

public:
	DropBasket(QWidget *parent = 0);
	~DropBasket();

public slots:
	void startClient();
	void newClientConnected();
	void readFromServ();
	void readFromClient();
	void startServer();
	void clientSend();

private:
	Ui::DropBasketClass ui;
};

#endif // DROPBASKET_H
