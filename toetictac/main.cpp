#include "toetictac.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Toetictac w;
	w.setWindowTitle("Tic Tac Toe");
	w.show();
	w.gameStart();
	return a.exec();
}
