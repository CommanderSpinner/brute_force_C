#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Brute Forcer");
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}
