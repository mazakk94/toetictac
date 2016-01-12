#include "toetictac.h"
#include <QMessageBox>
#include <string>

//#include <iostream>
//#include <QProcess>
//#include <QDesktopServices>
//#include <codecvt>

using namespace std;
QTcpSocket *clientSock;
vector<QTcpSocket*> clients; 
int clientCount = 0;
QTcpServer *serv;
QByteArray isTeam1;

int numOfTeam1 = 0;
int numOfTeam2 = 0;
bool whichTurn = 0; // 0 - gracz 1
					// 1 - gracz 2

int tmpClientTeam = 0;
int tmpClientID = 0;

/*
      CZÊŒÆ GRY
*/
QString playerName; //Player's symbol
QString playerName2; //Player's symbol


//Labels
QString gameBegin = "Game has begun.";
QString won1 = "Team 1 won.";
QString won2 = "Team 2 won.";

int wins = 0;
int wins2 = 0;
int draws = 1;
int moves = 0;
bool moved;

/*
	CZÊŒÆ SERWERA
*/
void Toetictac::newClientConnected() {
	/*
		zliczamy tutaj liczbe graczy
	*/
	QTcpSocket* newClient = serv->nextPendingConnection();
	
	clients.push_back(newClient);
	ui.textEdit->append("clients count: ");
	ui.textEdit->append(QString::number(clients.size()));

	connect(newClient, &QTcpSocket::readyRead, this, &Toetictac::readFromClient);
	clientCount++;
	//readFromClient();
	ui.textEdit->append(QString::number(clientCount));
	ui.textEdit->append("team gracza:");
	QString s = QString::number(tmpClientTeam);
	ui.textEdit->append(s);
	
	ui.pushButton69->setText("Odebrano gracza");
}

void Toetictac::startServer() {

	serv = new QTcpServer(this);
	connect(serv, &QTcpServer::newConnection, this, &Toetictac::newClientConnected);
	serv->listen(QHostAddress::Any, 1111);

	ui.pushButton69->setText("Serwer utworzony");
}


void Toetictac::readFromClients() {
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i]->bytesAvailable() != 0) {
			QByteArray arr = clients[i]->readAll();
			QString clientID = arr.mid(0, 1);
			tmpClientTeam = clientID.split(" ")[0].toInt();
		
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



void Toetictac::readFromClient() {
	
	for (int i = 0; i < clients.size(); i++){
		QString team = "";

		ui.textEdit->append("jestem w readFromClient ... liczba bajtow odebranych od klienta nr" + i);
		ui.textEdit->append(QString::number(clients[0]->bytesAvailable()));
		if (clients[0]->bytesAvailable() != 0) {
			ui.textEdit->append("jestem w if ...");
			QByteArray arr = clients[0]->readAll();
			QString clientTeam = arr.mid(0, 1);
			ui.textEdit->append("probuje odczytac druzyne klienta ...");
			team = clientTeam;
			ui.textEdit->append(team);
			tmpClientTeam = clientTeam.split(" ")[0].toInt();

			if ((whichTurn == 0 && tmpClientTeam == 1) || (whichTurn == 1 && tmpClientTeam == 2)){
				QString info("Gracz numer ");

				if (tmpClientTeam == 1)
					whichTurn = 1; //czas na druzyne 2
				else
					whichTurn = 0; //czas na druzyne 1

				QString info2(": ");
				QString msg(info + tmpClientTeam + info2 + arr.mid(1, arr.size()));
				ui.textEdit->append(msg);

			}


		}
		ui.textEdit->append("jestem za ifem ...");
	}

	//ui.textEdit->append(arr);
	//QByteArray arr2 = arr;
	//QString str(QString::fromUtf8(arr));
	//QString str = arr;
	//QStringRef clientID(str, 0, 1);
	
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
	clientSend();
}

void Toetictac::readFromServ() {
	
	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);
	ui.textEdit->append(str);
}


void Toetictac::clientSend() {
	QString msg((QString::fromUtf8(isTeam1)) + ui.fClientMsg->text().toUtf8());
	ui.textEdit->append("Wyswietlam msg klienta: ");
	ui.textEdit->append(msg);
	//QByteArray msgbyte((const char*)(msg.utf16()), msg.size() * 2);
	QByteArray msgbyte = msg.toUtf8();
	ui.textEdit->append(msgbyte);
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
	QObject::connect(ui.pushButton69, SIGNAL(clicked()), this, SLOT(startServer()));
	QObject::connect(ui.fJoinToServ, SIGNAL(clicked()), this, SLOT(startClient()));
	QObject::connect(ui.fClientSend, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.fServerSend, SIGNAL(clicked()), this, SLOT(serverSend()));
	QObject::connect(ui.bTeam1, SIGNAL(clicked()), this, SLOT(jointEam1()));
	QObject::connect(ui.bTeam2, SIGNAL(clicked()), this, SLOT(jointEam2()));
}

Toetictac::~Toetictac()
{
}


void Toetictac::gameStart() {

	playerName = "O";
	playerName2 = "X";
	moved = true;

}

void Toetictac::clear() {
	ui.label->setText("");
	ui.pushButton->setText("");
	ui.pushButton_2->setText("");
	ui.pushButton_3->setText("");
	ui.pushButton_4->setText("");
	ui.pushButton_5->setText("");
	ui.pushButton_6->setText("");
	ui.pushButton_7->setText("");
	ui.pushButton_8->setText("");
	ui.pushButton_9->setText("");

	moves = 0;
	//ui.label->setText(gameBegin);
}

void Toetictac::win() {
	QMessageBox wi;
	wi.setWindowTitle("Team 1 won.");
	wi.setText("Team 1 won.");
	wi.exec();
}

void Toetictac::win2() {
	QMessageBox wi2;
	wi2.setWindowTitle("Team 2 won.");
	wi2.setText("Team 2 won.");
	wi2.exec();
}

//check if player won or draw
bool Toetictac::check() { //Returns true if game is finished

	//horizontally
	if ((ui.pushButton->text().contains(playerName)) && (ui.pushButton_2->text().contains(playerName)) && (ui.pushButton_3->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_4->text().contains(playerName)) && (ui.pushButton_5->text().contains(playerName)) && (ui.pushButton_6->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_7->text().contains(playerName)) && (ui.pushButton_8->text().contains(playerName)) && (ui.pushButton_9->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}

	//vertical
	else if ((ui.pushButton->text().contains(playerName)) && (ui.pushButton_4->text().contains(playerName)) && (ui.pushButton_7->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_2->text().contains(playerName)) && (ui.pushButton_5->text().contains(playerName)) && (ui.pushButton_8->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_3->text().contains(playerName)) && (ui.pushButton_6->text().contains(playerName)) && (ui.pushButton_9->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}

	//aslant
	else if ((ui.pushButton->text().contains(playerName)) && (ui.pushButton_5->text().contains(playerName)) && (ui.pushButton_9->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_3->text().contains(playerName)) && (ui.pushButton_5->text().contains(playerName)) && (ui.pushButton_7->text().contains(playerName))) {
		wins++;
		ui.label->setText(won1);
		ui.label_6->setText(QString::number(wins));
		win();
		draws++;
		clear();
		return true;
	}

	//Draw
	if (moves == 9) {
		draws++;
		clear();
		return true;
	}

	moved = false;
	return false;
}

//check if CPU won or draw
bool Toetictac::check2() { //Returns true if game is finished

	//horizontally
	if ((ui.pushButton->text().contains(playerName2)) && (ui.pushButton_2->text().contains(playerName2)) && (ui.pushButton_3->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_4->text().contains(playerName2)) && (ui.pushButton_5->text().contains(playerName2)) && (ui.pushButton_6->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_7->text().contains(playerName2)) && (ui.pushButton_8->text().contains(playerName2)) && (ui.pushButton_9->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}

	//vertical
	else if ((ui.pushButton->text().contains(playerName2)) && (ui.pushButton_4->text().contains(playerName2)) && (ui.pushButton_7->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_2->text().contains(playerName2)) && (ui.pushButton_5->text().contains(playerName2)) && (ui.pushButton_8->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_3->text().contains(playerName2)) && (ui.pushButton_6->text().contains(playerName2)) && (ui.pushButton_9->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}

	//aslant
	else if ((ui.pushButton->text().contains(playerName2)) && (ui.pushButton_5->text().contains(playerName2)) && (ui.pushButton_9->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}
	else if ((ui.pushButton_3->text().contains(playerName2)) && (ui.pushButton_5->text().contains(playerName2)) && (ui.pushButton_7->text().contains(playerName2))) {
		wins2++;
		ui.label->setText(won2);
		ui.label_8->setText(QString::number(wins2));
		win2();
		draws++;
		clear();
		return true;
	}

	//Draw
	if (moves == 9) {
		draws++;
		clear();
		return true;
	}

	moved = true;
	return false;
}

//Restart button
void Toetictac::on_pushButton_11_clicked()
{
	qApp->quit();
	QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


//----------------------------PLAYERS BUTTONS BEGIN---------------------------------
void Toetictac::on_pushButton_clicked()
{

	if (ui.pushButton->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton->setText(playerName);
		moves++;
		cout << "Player 1 move into 1" << endl;
		check();
		if (moved){ moved = false; };
	}

	else if (ui.pushButton->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton->setText(playerName2);
		moves++;
		cout << "Player 2 move into 1" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_2_clicked()
{

	if (ui.pushButton_2->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_2->setText(playerName);
		moves++;
		cout << "Player 1 move into 2" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_2->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_2->setText(playerName2);
		moves++;;
		cout << "Player 2 move into 2" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_3_clicked()
{

	if (ui.pushButton_3->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_3->setText(playerName);
		moves++;
		cout << "Player 1 move into 3" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_3->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_3->setText(playerName2);
		moves++;
		cout << "Player 2 move into 3" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_4_clicked()
{

	if (ui.pushButton_4->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_4->setText(playerName);
		moves++;
		cout << "Player 1 move into 4" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_4->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_4->setText(playerName2);
		moves++;
		cout << "Player 2 move into 4" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_5_clicked()
{

	if (ui.pushButton_5->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_5->setText(playerName);
		moves++;
		cout << "Player 1 move into 5" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_5->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_5->setText(playerName2);
		moves++;
		cout << "Player 2 move into 5" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_6_clicked()
{

	if (ui.pushButton_6->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_6->setText(playerName);
		moves++;
		cout << "Player 1 move into 6" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_6->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_6->setText(playerName2);
		moves++;
		cout << "Player 2 move into 6" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_7_clicked()
{

	if (ui.pushButton_7->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_7->setText(playerName);
		moves++;
		cout << "Player 1 move into 7" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_7->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_7->setText(playerName2);
		moves++;
		cout << "Player 2 move into 7" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_8_clicked()
{

	if (ui.pushButton_8->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_8->setText(playerName);
		moves++;
		cout << "Player 1 move into 8" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_8->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_8->setText(playerName2);
		moves++;
		cout << "Player 2 move into 8" << endl;
		check2();
		if (moved){ moved = true; };
	}
}

void Toetictac::on_pushButton_9_clicked()
{

	if (ui.pushButton_9->text().toStdString().compare("") == 0 && moved) {
		ui.pushButton_9->setText(playerName);
		moves++;
		cout << "Player 1 move into 9" << endl;
		check();
		if (moved){ moved = false; };
	}
	else if (ui.pushButton_9->text().toStdString().compare("") == 0 && !moved) {
		ui.pushButton_9->setText(playerName2);
		moves++;
		cout << "Player 2 move into 9" << endl;
		check2();
		if (moved){ moved = true; };
	}
}
//----------------------------PLAYERS BUTTONS END--------------------------------