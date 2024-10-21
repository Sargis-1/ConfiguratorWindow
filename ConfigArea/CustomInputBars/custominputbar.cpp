#include "custominputbar.h"

CustomInputBar::CustomInputBar(const QString &labelText, int width, int height, float partition, QWidget* parent) : QWidget(parent)
{
    m_hboxlayout = new QHBoxLayout;
    m_hboxlayout->setContentsMargins(0, 0, 0, 0);
    m_hboxlayout->setSpacing(0);

    nameLabel = new QLabel(labelText);
    nameLabel->setFixedSize(width * partition, height);
    nameLabel->setStyleSheet("font-weight: bold; font-size: 14px; border: none;");

    inputPart = new QLineEdit;
    inputPart->setFixedSize(width - nameLabel->width(), height);
    inputPart->setStyleSheet("font-weight: bold; font-size: 14px; border: 2px solid black;");


    m_hboxlayout->addWidget(nameLabel, 0 , Qt::AlignLeft);
    m_hboxlayout->addWidget(inputPart, 3, Qt::AlignLeft);

    m_hboxlayout->setSpacing(0);
    //m_hboxlayout->setContentsMargins(30, 10, 30, 0);

    setLayout(m_hboxlayout);
}

QString CustomInputBar::getText()
{
    return inputPart->text();
}

void CustomInputBar::setText(const QString &text)
{
    inputPart->setText(text);
}

