#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customtitlebar.h"
#include <QHBoxLayout>
#include "../ConfigArea/Configurations/configurations.h"
#include "../SymbolArea/symbol.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
    QHBoxLayout* bothSections;
    Configurations* configs;
    Symbol* symbols;
};
#endif // MAINWINDOW_H
