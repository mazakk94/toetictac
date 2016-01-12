#ifndef TOETICTAC_H
#define TOETICTAC_H

#include <QtWidgets/QMainWindow>
#include "ui_toetictac.h"
#include <QWidget>
#include <QtNetwork>
#include <iostream>
#include <string>

namespace Ui {
	class Toetictac;
}

class Toetictac : public QMainWindow
{
	Q_OBJECT

public:
	Toetictac(QWidget *parent = 0);
	~Toetictac();

public slots:
	void playerJoint();
	void startClient();
	void newClientConnected();
	void readFromServ();
	void readFromClient();
	void readFromClients();
	void startServer();
	void clientSend();
	void serverSend();
	void voteForButton();
	void jointEam1();
	void jointEam2();


	bool check();
	bool check2();
	void gameStart();
	void win();
	void win2();
	void clear();
	void on_pushButton_11_clicked();

private:
	Ui::ToetictacClass ui;
	private slots:

	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();
};

#endif // TOETICTAC_H