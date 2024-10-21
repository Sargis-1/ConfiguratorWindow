#include "textinputbar.h"


TextInputBar::TextInputBar(const QString& labelText, int width, int height, float partition, const std::function<bool(const QString&)>& validator, QWidget* parent)
    : CustomInputBar(labelText, width, height, partition, parent), inputValidator(validator)
{
    connect(inputPart, &QLineEdit::returnPressed, this, &TextInputBar::handleInput);
}

void TextInputBar::setText(const QString &text)
{
    if(inputValidator(text)){
        inputPart->setText(text);
        return;
    }

    qDebug() << "Wrong input\n";
}

void TextInputBar::handleInput()
{

    QString inputText = inputPart->text();
    if(!inputValidator(inputText)){
        inputPart->clear();
        qDebug() << "Wrong input\n";
        return;
    }

    if(nameLabel->text() == "Number of pins: "){
        emit pinCountEntered();
    }
}


