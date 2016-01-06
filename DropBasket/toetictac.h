#ifndef TOETICTAC_H
#define TOETICTAC_H

#include <QtWidgets/QMainWindow>
#include "ui_toetictac.h"
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
	void serverSend();

private:
	Ui::DropBasketClass ui;
};

#endif // TOETICTAC_H
