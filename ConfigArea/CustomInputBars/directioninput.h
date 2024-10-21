#ifndef DIRECTIONINPUT_H
#define DIRECTIONINPUT_H

#include <QComboBox>
#include "custominputbar.h"

class DirectionInput : public CustomInputBar
{
private:
    enum class Direction{
        input,
        output
    };
    Direction direction = Direction::input;
    QComboBox* dropdown;
public:
    DirectionInput(const QString& labelText, int width, int height, float partition, QWidget* parent = nullptr);

    QString getDirection();

    void setText(const QString &text) override;
private slots:
    void handleInput(const QString &selectedOption);
};

#endif // DIRECTIONINPUT_H
