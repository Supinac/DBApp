#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("DBApp");

    connect(ui->m_pullBtn, &QPushButton::clicked, this, &MainWindow::onPull);
    connect(ui->m_saveBtn, &QPushButton::clicked, this, &MainWindow::onSave);
    connect(ui->m_loadBtn, &QPushButton::clicked, this, &MainWindow::onLoad);
    connect(ui->m_pushBtn, &QPushButton::clicked, this, &MainWindow::onPush);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onPull() {
    qDebug() << "Pull: slug =" << ui->m_slugEdit->text();
}

void MainWindow::onSave() {
    qDebug() << "Save: slug =" << ui->m_slugEdit->text()
             << "title =" << ui->m_titleEdit->text();
}

void MainWindow::onLoad() {
    qDebug() << "Load: slug =" << ui->m_slugEdit->text();
}

void MainWindow::onPush() {
    qDebug() << "Push: slug =" << ui->m_slugEdit->text()
             << "title =" << ui->m_titleEdit->text();
}
