#include "pin.h"

Pin::Pin(int width, int height, QWidget* parent) : QFrame(parent){
    setFixedSize(width, height * 5);

    pinLayout = new QVBoxLayout(this);
    pinLayout->setContentsMargins(0, 0, 0, 0);
    pinLayout->setSpacing(0);

    pinTitle = new CustomTitleBar("Pin " + QString::number(m_id++), width, height);
    pinTitle->setAlignment(Qt::AlignTop);
    pinTitle->setMargins(0, 0, 0, 0);
    pinTitle->setTitleStyleSheet("background-color: #A9A9A9; border-top: none; border-left: none; border-right: 3px solid black; border-bottom: 2px solid black;");
    pinLayout->addWidget(pinTitle);


    firstBarRow = new QHBoxLayout;
    firstBarRow->setContentsMargins(0, 0, 0, 0);
    firstBarRow->setSpacing(0);
    auto nameValidator = [](const QString& str) -> bool {
        return std::all_of(str.begin(), str.end(), [](QChar c) {
            return c.isLetterOrNumber();
        });
    };
    nameInput = new TextInputBar("Name: ", width / 2 - 25, height, 0.5, nameValidator);
    nameInput->setContentsMargins(10, 5, 10, 15);
    firstBarRow->addWidget(nameInput);

    directionInput = new DirectionInput("Direction: ", width / 2 - 25, height, 0.5);
    directionInput->setContentsMargins(10, 5, 10, 15);
    firstBarRow->addWidget(directionInput);

    secondBarRow = new QHBoxLayout;
    secondBarRow->setContentsMargins(0, 0, 0, 0);
    secondBarRow->setSpacing(0);

    enableBusRange = new EnableBusRangeInput("Enable bus range: ", width / 2 - 25, height, 0.5);
    enableBusRange->setContentsMargins(10, 5, 10, 15);
    secondBarRow->addWidget(enableBusRange);



    connect(enableBusRange, &EnableBusRangeInput::busRangeEnabled, this, &Pin::onBusRangeEnabled);

    pinLayout->addLayout(firstBarRow);
    pinLayout->addLayout(secondBarRow);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setLayout(pinLayout);
}

Pin::Pin(Pin &&rhs) noexcept
    : QFrame(nullptr),
    pinLayout(rhs.pinLayout),
    pinTitle(rhs.pinTitle),
    nameInput(rhs.nameInput),
    directionInput(rhs.directionInput),
    enableBusRange(rhs.enableBusRange),
    range(rhs.range),
    firstBarRow(rhs.firstBarRow),
    secondBarRow(rhs.secondBarRow)
{
    rhs.pinLayout = nullptr;
    rhs.pinTitle = nullptr;
    rhs.nameInput = nullptr;
    rhs.directionInput = nullptr;
    rhs.enableBusRange = nullptr;
    rhs.range = nullptr;
    rhs.firstBarRow = nullptr;
    rhs.secondBarRow = nullptr;
}


Pin& Pin::operator=(Pin &&rhs) noexcept {
    if (this != &rhs) {
        delete pinLayout;
        delete pinTitle;
        delete nameInput;
        delete directionInput;
        delete enableBusRange;
        delete range;
        delete firstBarRow;
        delete secondBarRow;

        pinLayout = rhs.pinLayout;
        pinTitle = rhs.pinTitle;
        nameInput = rhs.nameInput;
        directionInput = rhs.directionInput;
        enableBusRange = rhs.enableBusRange;
        range = rhs.range;
        firstBarRow = rhs.firstBarRow;
        secondBarRow = rhs.secondBarRow;

        rhs.pinLayout = nullptr;
        rhs.pinTitle = nullptr;
        rhs.nameInput = nullptr;
        rhs.directionInput = nullptr;
        rhs.enableBusRange = nullptr;
        rhs.range = nullptr;
        rhs.firstBarRow = nullptr;
        rhs.secondBarRow = nullptr;
    }
    return *this;
}

void Pin::setMargins(int left, int top, int right, int bottom)
{
    pinLayout->setContentsMargins(left, top, right, bottom);
}

void Pin::setId(int value)
{
    m_id = value;
}

QString Pin::getName() const
{
    return nameInput->getText();
}

QString Pin::getDirection() const
{
    return directionInput->getDirection();
}

QString Pin::hasBusRange() const
{
    return enableBusRange->isBusPin();
}

QString Pin::getRange() const
{
    return range->getText();
}

void Pin::setName(const QString &name)
{
    nameInput->setText(name);
}

void Pin::setDirection(const QString &name)
{
    directionInput->setText(name);
}

void Pin::setBusRange(const QString &name)
{
    enableBusRange->setText(name);
}

void Pin::setRange(const QString &name)
{
    range->setText(name);
}


void Pin::onBusRangeEnabled()
{

    if(enableBusRange->isBusPin() == "1"){
        auto validateRange = [](const QString& input) -> bool{
            std::regex pattern(R"(^\[(\d+):(\d+)\]$)");

            return std::regex_match(input.toStdString(), pattern);
        };
        range = new TextInputBar("Range: ", pinTitle->width() / 2 - 25, pinTitle->height(), 0.5, validateRange);
        range->setContentsMargins(20, 5, 10, 10);
        secondBarRow->addWidget(range);
    }else{
        delete range;
        range = nullptr;
    }
}


