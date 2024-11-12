#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , label(new QLabel(this))
{
    ui->setupUi(this);
    label->setText("Hello!");
    setCentralWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete label;
}
