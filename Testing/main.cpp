#include <QApplication>
#include <QPushButton>
#include <QTestAccessibility>
#include "MainWindowTesting.h"

int main(int argc, char *argv[]) {

    MainWindowTesting mainWindowTesting;

   QTest::qExec(&mainWindowTesting, argc, argv);

}
