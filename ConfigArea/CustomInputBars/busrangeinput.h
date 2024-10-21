#ifndef BUSRANGEINPUT_H
#define BUSRANGEINPUT_H

#include "QMouseEvent"
#include "custominputbar.h"

class EnableBusRangeInput : public CustomInputBar {
     Q_OBJECT
public:
    EnableBusRangeInput(const QString& labelText, int width, int height, float partition, QWidget* parent = nullptr);

    QString isBusPin();

    void setText(const QString &text) override;
private:
    void mousePressEvent(QMouseEvent* event) override;
signals:
    void busRangeEnabled();
private:
    bool isClicked;
};

#endif // BUSRANGEINPUT_H
