//
// Created by user on 26.12.2023.
//

#ifndef CLIENT_WINDOWSETUP_H
#define CLIENT_WINDOWSETUP_H



#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>
#include <QLabel>
#include <QPlainTextEdit>
#include <QSplitter>
#include <QFormLayout>
#include <QSpinBox>
#include "UserActivityHandler.h"
#include "ResponseHandler.h"

class WindowSetup {
private:
    QApplication app;
    QWidget window;
    UserActivityHandler& handler;

public:
    QTextEdit *productsTextEdit;
    QPushButton *confirmButton = new QPushButton("Add");
    QSpinBox *spinBox = new QSpinBox;
    QLineEdit *textEdit = new QLineEdit;
    void start_setup();
    WindowSetup (int argc, char *argv[], UserActivityHandler handler);
    void set_product_list(std::list<std::string> products,  QTextEdit* productsTextEdit);


};


#endif //CLIENT_WINDOWSETUP_H
