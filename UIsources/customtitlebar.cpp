#include "../UIheaders/customtitlebar.h"

CustomTitleBar::CustomTitleBar(const QString& title, QWidget* parent) : QWidget(parent) {
    setStyleSheet("background-color: #A9A9A9; border: 2px solid black;");
    setFixedHeight(30);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 0, 5, 0);
    layout->setSpacing(0);

    titleLabel = new QLabel(title);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: black; font-weight: bold; font-size: 14px;");

    layout->addWidget(titleLabel);

    setLayout(layout);
}

CustomTitleBar::CustomTitleBar(const QString &title, int width, int height, QWidget *parent): QWidget(parent)
{
    setStyleSheet("background-color: #A9A9A9; border: 2px solid black;");
    setFixedWidth(width);
    setFixedHeight(height);

    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    titleLabel = new QLabel(title);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: black; font-weight: bold; font-size: 14px;");
    titleLabel->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(titleLabel);

    setLayout(layout);
}

void CustomTitleBar::setTitleStyleSheet(const QString &style)
{
    this->setStyleSheet(style);
}

void CustomTitleBar::setMargins(int left, int top, int right, int bottom)
{
    layout->setContentsMargins(left, top, right, bottom);
}

void CustomTitleBar::setAlignment(Qt::AlignmentFlag flag)
{
    titleLabel->setAlignment(flag);
}
