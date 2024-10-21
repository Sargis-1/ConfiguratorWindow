#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <QScreen>
#include <QGuiApplication>
#include <QRect>
#include <QVector>
#include "../../UIheaders/customtitlebar.h"
#include "../CustomInputBars/custominputbar.h"
#include "../Pin/pin.h"
#include "../PinManager/pinmanager.h"

class Configurations : public QWidget
{
    Q_OBJECT
public:
    Configurations(QWidget* parent = nullptr);

    void addPins();

    ~Configurations();

    void saveState() const;

    void loadState();
private:
    QWidget* configWidget;
    QVBoxLayout* layout;
    CustomTitleBar* configTitle;
    TextInputBar* pinCount;
    QVector<Pin*> pins;
};

#endif // CONFIGURATIONS_H
