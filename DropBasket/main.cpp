#include "toetictac.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DropBasket w;

	w.show();
	return a.exec();
}
