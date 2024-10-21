#include "../UIheaders/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(1000, 600);

    centralWidget = new QWidget(this);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    CustomTitleBar* titleBar = new CustomTitleBar("Configurator window", centralWidget);
    titleBar->setMargins(5, 0, 5, 0);
    mainLayout->addWidget(titleBar);

    bothSections = new QHBoxLayout(centralWidget);

    configs = new Configurations(centralWidget);
    symbols = new Symbol(centralWidget);

    bothSections->addWidget(configs);
    bothSections->addWidget(symbols);

    mainLayout->addLayout(bothSections);

    setCentralWidget(centralWidget);
    showMaximized();
}

MainWindow::~MainWindow()
{
}
