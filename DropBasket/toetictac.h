#ifndef TOETICTAC_H
#define TOETICTAC_H

#include <QtWidgets/QMainWindow>
#include "ui_toetictac.h"
#include <QWidget>
#include <QtNetwork>

class Toetictac : public QMainWindow
{
	Q_OBJECT

public:
	Toetictac(QWidget *parent = 0);
	~Toetictac();

public slots:
	void startClient();
	void newClientConnected();
	void readFromServ();
	void readFromClient();
	void startServer();
	void clientSend();
	void serverSend();

private:
	Ui::ToetictacClass ui;
};

#endif // TOETICTAC_H
