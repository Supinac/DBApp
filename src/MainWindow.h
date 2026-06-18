#pragma once
#include "ApiClient.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void onPull();
	void onSave();
	void onLoad();
	void onPush();
	void onPushNew();

private:
	Ui::MainWindow *ui;
	ApiClient *m_api;
};
