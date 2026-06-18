#pragma once
#include <QMainWindow>

class QLabel;
class QPushButton;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  void onClicked();

private:
  QLabel *m_label = nullptr;
  QPushButton *m_button = nullptr;
  int m_count = 0;
};
