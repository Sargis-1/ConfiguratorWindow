#include "directioninput.h"

DirectionInput::DirectionInput(const QString& labelText, int width, int height, float partition, QWidget* parent)
    : CustomInputBar(labelText, width, height, partition, parent), dropdown(new QComboBox)
{

    QVBoxLayout* dropdownLayout = new QVBoxLayout;

    dropdown->addItem("Input");
    dropdown->addItem("Output");

    dropdown->setFixedSize(width - nameLabel->width(), height);
    dropdown->setStyleSheet("font-weight: bold; font-size: 14px; border: 2px solid black;");

    connect(dropdown, &QComboBox::currentTextChanged, this, [&](const QString &selectedOption){
        if (selectedOption == "Input") {
            direction = Direction::input;
            dropdown->setCurrentText("Input");
        } else if (selectedOption == "Output") {
            direction = Direction::output;
            dropdown->setCurrentText("Output");
        }
    });

    delete inputPart;

    dropdownLayout->addWidget(dropdown);
    m_hboxlayout->addLayout(dropdownLayout);
}

QString DirectionInput::getDirection()
{
    if(direction == Direction::input){
        return "Input";
    }else{
        return "Output";
    }
}

void DirectionInput::setText(const QString &text)
{
    if(text == "Input"){
        direction = Direction::input;
    }else if(text == "Output"){
        direction = Direction::output;
    }else{
        qDebug() << "Wrong input\n";
    }
}


