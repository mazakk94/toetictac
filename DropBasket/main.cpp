#include "toetictac.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Toetictac w;

	w.show();
	return a.exec();
}
