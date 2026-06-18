#pragma once
#include <QMainWindow>

class<QtClassYouNeed>;
class<AnotherQtClassYouNeed>;

class<YourClassName> : public QMainWindow {
  Q_OBJECT
public:
  explicit<YourClassName>(QWidget *parent = nullptr);

private slots:
  void<slotName1>();
  void<slotName2>(const QString &<argName>);

private:
  <QtClassYouNeed> *memberPtr1 = nullptr;
  <AnotherQtClassYouNeed> *memberPtr2 = nullptr;
};

Rule of thumb on whether a widget needs to be a member
    : -Yes,
      if a slot has to talk to it later(e.g.m_titleEdit — onSave reads it) - No,
      if it's just glue used during construction (layouts, panels — make them locals)

      Constructor body(MainWindow.cpp)

      <YourClassName>::<YourClassName>(QWidget *parent)
    : QMainWindow(parent) {
  setWindowTitle(<"App name">);

  setCentralWidget(<rootWidget>);
