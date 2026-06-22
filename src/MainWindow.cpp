#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	setWindowTitle("DBApp");

	m_api = new ApiClient(this);
	connect(m_api, &ApiClient::pulled, this, [this](const QString &title, const QString &body) {
		ui->m_titleEdit->setText(title);
		ui->m_bodyEdit->setPlainText(body);
	});

	connect(m_api, &ApiClient::pushed, this, [this]() { statusBar()->showMessage("Saved", 2000); });
	connect(m_api, &ApiClient::errored, this, [](const QString &msg) { qWarning() << "API error:" << msg; });
	connect(ui->m_pullBtn, &QPushButton::clicked, this, &MainWindow::onPull);
	connect(ui->m_pushBtn, &QPushButton::clicked, this, &MainWindow::onPush);
	connect(ui->m_pushNewBtn, &QPushButton::clicked, this, &MainWindow::onPushNew);
	connect(ui->m_clearBtn, &QPushButton::clicked, this, &MainWindow::onClear);
}

void MainWindow::onClear() {
	ui->m_titleEdit->clear();
	ui->m_bodyEdit->clear();
	ui->m_slugEdit->clear();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onPull() { m_api->pull(ui->m_slugEdit->text()); }
void MainWindow::onPush() {
	m_api->push(ui->m_slugEdit->text(), ui->m_titleEdit->text(), ui->m_bodyEdit->toPlainText());
}
void MainWindow::onPushNew() {
	m_api->pushNew(ui->m_slugEdit->text(), ui->m_titleEdit->text(), ui->m_bodyEdit->toPlainText());
}
