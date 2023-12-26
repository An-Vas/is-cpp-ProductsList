#include "WindowSetup.h"

WindowSetup::WindowSetup(int argc, char *argv[], UserActivityHandler handler) : app(QApplication(argc, argv)), handler(handler) {
    window.setWindowTitle("Products List");
}

void WindowSetup::start_setup() {
    QVBoxLayout *leftLayout = new QVBoxLayout;


    QPushButton *button = new QPushButton("Clear the list");
    QObject::connect(button, &QPushButton::clicked, [this]() {
        auto products = handler.handle_clear_list();
        auto productsList = ResponseHandler::handle(products);
        set_product_list(productsList, productsTextEdit);
    });

    button->setAutoFillBackground(true);
    button->setFlat(true);
    QPalette p1 = button->palette();
    p1.setColor(QPalette::Button, QColor(255, 228, 196));
    button->setPalette(p1);


    leftLayout->addWidget(button);


    QPalette pal = app.palette();
    pal.setColor(QPalette::Window, QColor(255, 160, 122));
    app.setPalette(pal);


    QFormLayout *formLayout = new QFormLayout;

    formLayout->addRow("Product:", textEdit);

    formLayout->addRow("Count:", spinBox);



    confirmButton->setAutoFillBackground(true);
    confirmButton->setFlat(true);

    QPalette p = confirmButton->palette();
    p.setColor(QPalette::Button, QColor(255, 228, 196));
    confirmButton->setPalette(p);

    QObject::connect(confirmButton, &QPushButton::clicked, [=]() {
        auto products = handler.handle_add_product(textEdit->text().toStdString()  , spinBox->value());

        auto productsList = ResponseHandler::handle(products);
        set_product_list(productsList, productsTextEdit);

        productsTextEdit->clear();

        std::list<std::string>::iterator it;
        if (productsList.begin() == productsList.end()){
            productsTextEdit->append(QString("Add some products"));
        }

        for (auto const& i : productsList) {

            productsTextEdit->append(QString::fromStdString(i));
        }


    });
    formLayout->addWidget(confirmButton);

    leftLayout->addLayout(formLayout);


    QLabel *label = new QLabel("Current Product List");
    QVBoxLayout *rightLayout = new QVBoxLayout;
    productsTextEdit = new QTextEdit();

    rightLayout->addWidget(label);
    rightLayout->addWidget(productsTextEdit);
    rightLayout->addStretch();

    productsTextEdit->append(QString("Add some products"));


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addLayout(rightLayout, 5);

    mainLayout->addStretch();
    window.setLayout(mainLayout);
    window.show();
    app.exec();
}

void WindowSetup::set_product_list(std::list<std::string> products, QTextEdit* productsTextEdit){

    productsTextEdit->clear();

    std::list<std::string>::iterator it;
    if (products.begin() == products.end()){
        productsTextEdit->append(QString("Add some products"));
    }
    for (it = products.begin(); it != products.end(); ++it){
        productsTextEdit->append(QString::fromStdString(*it));
    }


}