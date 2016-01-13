#include "toetictac.h"
#include <QMessageBox>
#include <string>


using namespace std;

QTcpSocket *clientSock;
vector<QTcpSocket*> clients; 
vector<int> clientsTeams;
QTcpServer *serv;
QByteArray isTeam1;

int numOfTeam1 = 0;
int numOfTeam2 = 0;
bool whichTurn = 0; // 0 - gracz 1
					// 1 - gracz 2
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

vector<bool> teams(4, 0);
//teams = { 0, 0, 0, 0 };
bool acceptJoin = 0;

/*
	CZÊŒÆ SERWERA
*/
void Toetictac::newClientConnected() {
	/*
		zliczamy tutaj liczbe graczy

	*/
	QTcpSocket* newClient = serv->nextPendingConnection();
	clients.push_back(newClient);
	connect(newClient, &QTcpSocket::readyRead, this, &Toetictac::readFromClient);

	if (clients.size() == 4){
		ui.textEdit->append("jest 4 klientów");
		//wyslij wiadomosc do klientów
		serverSend("0111");
	}
	ui.pushButton69->setText("Odebrano klienta");
}

void Toetictac::startServer() {

	serv = new QTcpServer(this);
	connect(serv, &QTcpServer::newConnection, this, &Toetictac::newClientConnected);
	serv->listen(QHostAddress::Any, 1111);

	ui.pushButton69->setText("Serwer utworzony");
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
				                                                                      //////// DEMOKRACJA DZIWKO
				QString info2(": ");
				//QString msg(info + clientID + info2 + arr.mid(1, arr.size()));
				//QString msg(arr.mid(1, arr.size()));
				QString msg(arr.mid(1,1));
				election(msg);
				ui.textEdit->append(msg);
				break;
			} 
		}
	}
}



vector<bool> Toetictac::getTeams(string msg){

	vector<bool> teams(4, 1);
	for (int i = 0; i < 4; i++){
		if (msg[i] == '0')
			teams[i] = 0;
	}
	return teams;
}


void Toetictac::serverSend(QString msg) {
	for (int i = 0; i < clients.size(); i++) {
		//string mmsg = msg.toUtf8();
		//clients[i]->write(ui.fServerMsg->text().toUtf8());
		clients[i]->write(msg.toUtf8());
	}
}

void Toetictac::voteForButton(){
	//TODO
}

/*
	CZÊŒÆ KLIENTA
*/



void Toetictac::unlockButtons(){
	if (teams[0] == 0)
		ui.bTeam11->setEnabled(true);
	if (teams[1] == 0)
		ui.bTeam12->setEnabled(true);
	if (teams[2] == 0)
		ui.bTeam21->setEnabled(true);
	if (teams[3] == 0)
		ui.bTeam22->setEnabled(true);
}

void Toetictac::startClient() {

	clientSock = new QTcpSocket(this);
	connect(clientSock, &QTcpSocket::readyRead, this, &Toetictac::readFromServ);
	clientSock->connectToHost(ui.lineEdit->text(), ui.spinBox->value());

	
	QString text = "Wybierz slot gracza:";
	ui.fJoinToServ->setText(text);
	//unlockButtons();
}

void Toetictac::readFromServ() {
	
	QByteArray arr = clientSock->readAll();
	QString str = QString::fromUtf8(arr);
	
	if (str.length() == 4){
		teams = getTeams(str.toStdString());
		for (int o = 0; o < 4; o++){
			ui.textEdit->append(QString::number(teams[o]));
		}
	}

	unlockButtons();
	ui.textEdit->append(str);

	int x = str.split(" ")[0].toInt();

	switch (x)
	{
	case 1:
		ui.pushButton->setText(playerName);
		break;
	case 2:
		ui.pushButton->setText(playerName2);
		break;
	case 3:
		ui.pushButton_2->setText(playerName);
		break;
	case 4:
		ui.pushButton_2->setText(playerName2);
		break;
	case 5:
		ui.pushButton_3->setText(playerName);
		break;
	case 6:
		ui.pushButton_3->setText(playerName2);
		break;
	case 7:
		ui.pushButton_4->setText(playerName);
		break;
	case 8:
		ui.pushButton_4->setText(playerName2);
		break;
	case 9:
		ui.pushButton_5->setText(playerName);
		break;
	case 10:
		ui.pushButton_5->setText(playerName2);
		break;
	case 11:
		ui.pushButton_6->setText(playerName);
		break;
	case 12:
		ui.pushButton_6->setText(playerName2);
		break;
	case 13:
		ui.pushButton_7->setText(playerName);
		break;
	case 14:
		ui.pushButton_7->setText(playerName2);
		break;
	case 15:
		ui.pushButton_8->setText(playerName);
		break;
	case 16:
		ui.pushButton_8->setText(playerName2);
		break;
	case 17:
		ui.pushButton_9->setText(playerName);
		break;
	case 18:
		ui.pushButton_9->setText(playerName2);
		break;
	default:
		break;
	}
}


void Toetictac::clientSend() {
	QString msg((QString::fromUtf8(isTeam1)) + ui.fClientMsg->text().toUtf8());
	QByteArray msgbyte = msg.toUtf8();
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
	//ui.bTeam1->setEnabled(false);
	//ui.bTeam2->setEnabled(false);
}

Toetictac::Toetictac(QWidget *parent)
	: QMainWindow(parent)

{
	ui.setupUi(this);
	QObject::connect(ui.pushButton69, SIGNAL(clicked()), this, SLOT(startServer()));
	QObject::connect(ui.fJoinToServ, SIGNAL(clicked()), this, SLOT(startClient()));
	QObject::connect(ui.fClientSend, SIGNAL(clicked()), this, SLOT(clientSend()));
	QObject::connect(ui.fServerSend, SIGNAL(clicked()), this, SLOT(serverSend()));
	//QObject::connect(ui.bTeam1, SIGNAL(clicked()), this, SLOT(jointEam1()));
	//QObject::connect(ui.bTeam2, SIGNAL(clicked()), this, SLOT(jointEam2()));
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

void Toetictac::democracy()       ///SPRAWDZA CZY WSZYSCY Z DRUZYNY DALI GLOS
								  ///decyduje ktory klawisz
{

}

void Toetictac::election(QString baton)
{
	int x = baton.split(" ")[0].toInt();

	switch (x)
	{
	case 1:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "1";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "2";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;

	case 2:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "3";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "4";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 3:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "5";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "6";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 4:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "7";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "8";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 5:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "9";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "10";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 6:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "11";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "12";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 7:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "13";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "14";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 8:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "15";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "16";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	case 9:
		if (moved){
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "17";
				clients[i]->write(msg.toUtf8());
			}
			moves++;
			check();
		}
		else{
			for (int i = 0; i < clients.size(); i++) {
				QString msg = "18";
				clients[i]->write(msg.toUtf8());
			}
			moves++;;
			check2();
		}
		break;
	default:
		break;
	}
}

//----------------------------PLAYERS BUTTONS BEGIN---------------------------------
void Toetictac::on_pushButton_clicked()
{

	if (ui.pushButton->text().toStdString().compare("") == 0 && moved) {
		QString text = "1";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());    //// WYSYLANIE ID DRUZYNY
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}

	else if (ui.pushButton->text().toStdString().compare("") == 0 && !moved) {
		QString text = "1";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_2_clicked()
{

	if (ui.pushButton_2->text().toStdString().compare("") == 0 && moved) {
		QString text = "2";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
	else if (ui.pushButton_2->text().toStdString().compare("") == 0 && !moved) {
		QString text = "2";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_3_clicked()
{

	if (ui.pushButton_3->text().toStdString().compare("") == 0 && moved) {
		QString text = "3";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8()+ playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
		
	}
	else if (ui.pushButton_3->text().toStdString().compare("") == 0 && !moved) {
		QString text = "3";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_4_clicked()
{

	if (ui.pushButton_4->text().toStdString().compare("") == 0 && moved) {
		QString text = "4";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
	else if (ui.pushButton_4->text().toStdString().compare("") == 0 && !moved) {
		QString text = "4";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_5_clicked()
{

	if (ui.pushButton_5->text().toStdString().compare("") == 0 && moved) {
		QString text = "5";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
		
	}
	else if (ui.pushButton_5->text().toStdString().compare("") == 0 && !moved) {
		QString text = "5";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_6_clicked()
{

	if (ui.pushButton_6->text().toStdString().compare("") == 0 && moved) {
		QString text = "6";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
		
	}
	else if (ui.pushButton_6->text().toStdString().compare("") == 0 && !moved) {
		QString text = "6";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_7_clicked()
{

	if (ui.pushButton_7->text().toStdString().compare("") == 0 && moved) {
		QString text = "7";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
	else if (ui.pushButton_7->text().toStdString().compare("") == 0 && !moved) {
		QString text = "7";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_8_clicked()
{

	if (ui.pushButton_8->text().toStdString().compare("") == 0 && moved) {
		QString text = "8";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
	else if (ui.pushButton_8->text().toStdString().compare("") == 0 && !moved) {
		QString text = "8";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}

void Toetictac::on_pushButton_9_clicked()
{
	
	if (ui.pushButton_9->text().toStdString().compare("") == 0 && moved) {
		QString text = "9";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
	else if (ui.pushButton_9->text().toStdString().compare("") == 0 && !moved) {
		QString text = "9";
		QString msg((QString::fromUtf8(isTeam1)) + text.toUtf8() + playerName2.toUtf8());
		QByteArray msgbyte = msg.toUtf8();
		clientSock->write(msgbyte);
	}
}
//----------------------------PLAYERS BUTTONS END--------------------------------