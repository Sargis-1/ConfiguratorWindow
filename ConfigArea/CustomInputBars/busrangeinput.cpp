#include "busrangeinput.h"

EnableBusRangeInput::EnableBusRangeInput(const QString& labelText, int width, int height, float partition, QWidget* parent) :
    CustomInputBar(labelText, width, height, partition, parent) {
    inputPart->setReadOnly(true);
    isClicked = false;
    inputPart->setFixedSize(height, height);
    inputPart->setAttribute(Qt::WA_TransparentForMouseEvents, true); // This allows mouse events to pass through
}

void EnableBusRangeInput::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        isClicked = !isClicked;
        emit busRangeEnabled();
        if(isClicked){
            inputPart->setStyleSheet("background-color: blue");;
        }else{
            inputPart->setStyleSheet("background-color: white");;
        }
    }

    QWidget::mousePressEvent(event);
}

QString EnableBusRangeInput::isBusPin(){
    return isClicked ? "1" : "0";
}

void EnableBusRangeInput::setText(const QString &text)
{
    if(text == "1"){
        isClicked = true;
    }else if(text == "0"){
        isClicked = false;
    }else{
        qDebug() << "Wrong enable bus range input\n";
    }
}
