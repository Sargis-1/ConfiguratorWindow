#ifndef TEXTINPUTBAR_H
#define TEXTINPUTBAR_H

#include <functional>
#include "custominputbar.h"

class TextInputBar : public CustomInputBar
{
    Q_OBJECT
public:
    TextInputBar(const QString& labelText, int width, int height, float partition,  const std::function<bool(const QString&)>& validator,  QWidget *parent = nullptr);

    void setText(const QString &text) override;
private slots:
    void handleInput();
signals:
    void pinCountEntered();
private:
    std::function<bool(const QString&)> inputValidator;
};


#endif // TEXTINPUTBAR_H
