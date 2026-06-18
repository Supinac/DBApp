#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	app.setOrganizationName("Supinac");
	app.setApplicationName("DBApp");
	MainWindow w;
	w.show();
	return app.exec();
}
