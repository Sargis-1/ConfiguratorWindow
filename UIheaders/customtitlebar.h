#ifndef CUSTOMTITLEBAR_H
#define CUSTOMTITLEBAR_H

#include <QLabel>
#include <QHBoxLayout>

class CustomTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit CustomTitleBar(const QString& title, QWidget* parent = nullptr);
    explicit CustomTitleBar(const QString& title, int width, int height, QWidget* parent = nullptr);

    void setTitleStyleSheet(const QString &style);
    void setMargins(int left, int top, int right, int bottom);
    void setAlignment(Qt::AlignmentFlag flag);
private:
    QHBoxLayout* layout;
    QLabel* titleLabel;
};

#endif // CUSTOMTITLEBAR_H
