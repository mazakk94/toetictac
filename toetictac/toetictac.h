#ifndef TOETICTAC_H
#define TOETICTAC_H

#include <QtWidgets/QMainWindow>
#include "ui_toetictac.h"
#include <QWidget>
#include <QtNetwork>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
	void startServer();
	void clientSend();
	void serverSend(QString msg);
	void voteForButton();
	void jointEam1();
	void jointEam2();

	vector<bool> getTeams(string);
	void unlockButtons();


	bool check();
	bool check2();
	void gameStart();
	void win();
	void win2();
	void clear();
	void on_pushButton_11_clicked();
	void democracy();
	void election(QString baton);

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