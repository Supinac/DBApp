#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Hello");

  auto *layout = new QVBoxLayout(&window);
  auto *label = new QLabel("clicks: 0");
  auto *button = new QPushButton("push me");
  layout->addWidget(button);
  layout->addWidget(label);

  int count = 0;
  QObject::connect(button, &QPushButton::clicked, [&count, label]() {
    label->setText(QString("clicks: %1").arg(++count));
  });

  window.resize(400, 300);
  window.show();
  return app.exec();
}
