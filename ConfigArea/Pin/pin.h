#ifndef PIN_H
#define PIN_H

#include "../../UIheaders/customtitlebar.h"
#include "../CustomInputBars/textinputbar.h"
#include "../CustomInputBars/busrangeinput.h"
#include "../CustomInputBars/directioninput.h"
#include <QFrame>
#include <regex>

class Pin : public QFrame {
    Q_OBJECT
public:
    Pin(int width = 708, int height = 150, QWidget* parent = nullptr);

    Pin(Pin&& rhs) noexcept;

    Pin& operator=(Pin &&rhs) noexcept;

    void setMargins(int left, int top, int right, int bottom);

    static void setId(int value);

    QString getName() const;

    QString getDirection() const;

    QString hasBusRange() const;

    QString getRange() const;

    void setName(const QString& name);

    void setDirection(const QString& name);

    void setBusRange(const QString &name);

    void setRange(const QString& name);


private slots:
    void onBusRangeEnabled();
private:
    QVBoxLayout* pinLayout;
    CustomTitleBar* pinTitle;
    CustomInputBar* nameInput;
    DirectionInput* directionInput;
    EnableBusRangeInput* enableBusRange;
    CustomInputBar* range;
    QHBoxLayout* firstBarRow;
    QHBoxLayout* secondBarRow;
    inline static unsigned m_id = 1;
};

#endif // PIN_H
