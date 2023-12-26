#ifndef TESTING_MAINWINDOWTESTING_H
#define TESTING_MAINWINDOWTESTING_H

#include <QVBoxLayout>
#include <QtTest/QtTest>
#include "WindowSetup.h"
#include "UserActivityHandler.h"

class MainWindowTesting : public QObject {
Q_OBJECT
private slots:
    void test_set_product_list() {

        net::io_context ioc;
        Client client(ioc, {tcp::v4(), 8080});
        UserActivityHandler handler(client);
        WindowSetup windowSetup(0, nullptr, handler);


        QTextEdit productsTextEdit;

        QPushButton* addButton = windowSetup.confirmButton;
        QLineEdit* productNameEdit = windowSetup.textEdit;
        QSpinBox* productCountSpinbox = windowSetup.spinBox;

        QTest::mouseClick(addButton, Qt::LeftButton);
        QCOMPARE(productNameEdit->text(), QString(""));

        QTest::keyClicks(productNameEdit, "Product 1");

        QCOMPARE(productNameEdit->text(), QString("Product 1"));

        std::list<std::string> products = {"Product 1", "Product 2", "Product 3"};
        windowSetup.set_product_list(products, &productsTextEdit);
        QCOMPARE(productsTextEdit.toPlainText(), QString("Product 1\nProduct 2\nProduct 3"));


    }
};


#endif //TESTING_MAINWINDOWTESTING_H
