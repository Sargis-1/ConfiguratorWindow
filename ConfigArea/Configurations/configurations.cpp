#include "configurations.h"
#include "../CustomInputBars/textinputbar.h"


Configurations::Configurations(QWidget* parent) : QWidget(parent) {
    configWidget = new QWidget(this);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeo = screen->geometry();

    setFixedSize(screenGeo.width() / 2, screenGeo.height() - 30);
    configWidget->setFixedSize(screenGeo.width() / 2, screenGeo.height() - 30);

    screenGeo.setHeight(30);
    screenGeo.setWidth(screenGeo.width() / 2);


    layout = new QVBoxLayout(configWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);


    configTitle = new CustomTitleBar("Configurations", screenGeo.width(), screenGeo.height());
    configTitle->setMargins(5, 0, 0, 0);
    layout->addWidget(configTitle);

    pinCount = new TextInputBar("Number of pins: ", screenGeo.width() - 60, screenGeo.height(), 0.25, [](const QString& text) -> bool {
        bool ok;
        int value = text.toInt(&ok);
        return ok && (value > 0);
    });
    pinCount->setContentsMargins(20, 15, 20, 15);

    connect(pinCount, &TextInputBar::pinCountEntered, this, Configurations::addPins);//add pins according to pin count input

    layout->addWidget(pinCount, 0, Qt::AlignTop);


    setStyleSheet("border: 2px solid black;");

    configWidget->setLayout(layout);
}

void Configurations::addPins()
{
    unsigned pincount = pinCount->getText().toUInt();

    if(pincount == pins.size()){
        return;
    }else if(pincount < pins.size()){
        for(size_t i = pincount; i != pins.size(); ++i){
            delete pins[i];
        }
        pins.resize(pincount);
        Pin::setId(pincount + 1);
        return;
    }else{
        pins.reserve(pincount);
        pincount -= pins.size();
        while(pincount--){
            Pin* pin = new Pin(pinCount->width() - 60, 30);
            layout->addWidget(pin, 1, Qt::AlignTop);
            layout->setAlignment(pin, Qt::AlignCenter);
            pins.push_back(pin);
        }
    }
}

Configurations::~Configurations()
{
    for (Pin* pin : pins) {
        delete pin;
    }
}

void Configurations::saveState() const
{
    PinManager saver;
    saver.saveToJson(pins, "../State");
}

void Configurations::loadState()
{
    PinManager loader;
    loader.loadFromJson(pins, "../State");
}
