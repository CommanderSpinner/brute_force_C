#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "debugConsole.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <memory>
#include "httpreq.h"
#include "sender.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)//, ui(new Ui::MainWindow)
{
    std::unique_ptr<Ui::MainWindow> ui = std::make_unique<Ui::MainWindow>();
    ui->setupUi(this);
    this->setWindowTitle("Brute Forcer");
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::on_btn_Force_clicked()
{
    qDebug() << "Force button was pressed" << "\n";
    std::string url;
    std::string nameOfLoginNameField;
    std::string nameToLogin;
    std::string passwordFieldName;
    //std::unique_ptr<HttpReq> req = std::make_unique<HttpReq>();
    /*
    std::unique_ptr<Sender> send = std::make_unique<Sender>(
    url,
    nameOfLoginNameField,
    nameToLogin,
    passwordFieldName);*/

}
