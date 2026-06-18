#include "MainWindow.h"
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("DBApp");

  // --- LEFT PANEL ---------------------------------------------------------
  // create leftPanel as a new QWidget(this)
  auto *leftPanel = new QWidget(this);
  // create a QVBoxLayout attached to leftPanel
  auto *layout = new QVBoxLayout(leftPanel);
  // create the QListWidget (parented to leftPanel) and add it to the layout
  auto *listWidget = new QListWidget(leftPanel);
  layout->addWidget(listWidget);
  // create the new/delete row: QHBoxLayout + two QPushButtons, add to layout
  // create the reload button and add to layout

  // --- RIGHT PANEL --------------------------------------------------------
  // create rightPanel as a new QWidget(this)
  // create a QVBoxLayout attached to rightPanel
  // create QLineEdit for title, add to layout
  // create QTextEdit for body, add to layout
  // create Save button, add to layout

  // --- SPLITTER + WIRING --------------------------------------------------
  // create QSplitter(Qt::Horizontal, this)
  // splitter->addWidget(leftPanel); splitter->addWidget(rightPanel);
  // splitter->setSizes({200, 600});
  // setCentralWidget(splitter);

  // connect() the four buttons + the list's currentTextChanged
}
