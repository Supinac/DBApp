#include "MainWindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("DBApp");

  auto *central = new QWidget(this);
  auto *layout = new QVBoxLayout(central);

  m_label = new QLabel("clicks: 0", central);
  m_button = new QPushButton("Click me", central);
  layout->addWidget(m_label);
  layout->addWidget(m_button);

  setCentralWidget(central);

  connect(m_button, &QPushButton::clicked, this, &MainWindow::onClicked);
}

void MainWindow::onClicked() {
  m_label->setText(QString("clicks: %1").arg(++m_count));
}
