#ifndef CUSTOMINPUTBAR_H
#define CUSTOMINPUTBAR_H

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

class CustomInputBar : public QWidget
{
    Q_OBJECT
public:
    CustomInputBar(const QString& labelText, int width, int height, float partition, QWidget* parent = nullptr);

    virtual ~CustomInputBar() = default;

    QString getText();

    virtual void setText(const QString& text);
protected:
    QLabel* nameLabel;
    QLineEdit* inputPart;
    QHBoxLayout* m_hboxlayout;
};

#endif // CUSTOMINPUTBAR_H
