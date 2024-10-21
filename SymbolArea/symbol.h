#ifndef SYMBOL_H
#define SYMBOL_H

#include <QScreen>
#include <QGuiApplication>
#include <QRect>
#include "../UIheaders/customtitlebar.h"

class Symbol : public QWidget
{
    Q_OBJECT
public:
    Symbol(QWidget* parent = nullptr);
private:
    QWidget* symbolWidget;
    QVBoxLayout* symbolLayout;
    CustomTitleBar* symbolTitle;
};

#endif // SYMBOL_H
