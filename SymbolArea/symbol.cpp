#include "symbol.h"

Symbol::Symbol(QWidget* parent) : QWidget(parent) {
    symbolWidget = new QWidget(this);

    symbolLayout = new QVBoxLayout(symbolWidget);
    symbolLayout->setSpacing(0);
    symbolLayout->setContentsMargins(0, 0, 0, 0);


    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeo = screen->geometry();

    setFixedSize(screenGeo.width(), screenGeo.height() - 30);

    screenGeo.setHeight(30);
    screenGeo.setWidth(screenGeo.width() / 2);


    symbolTitle = new CustomTitleBar("Symbol", screenGeo.width(), screenGeo.height(), this);
    symbolTitle->setMargins(0, 0, 5, 0);
    symbolLayout->addWidget(symbolTitle);


    setStyleSheet("border: 2px solid black; border-left: none");

    symbolWidget->setLayout(symbolLayout);
}

