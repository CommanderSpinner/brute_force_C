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
    std::string url = ui->text_nameOfLoginNameField->toPlainText().toStdString();
    std::string nameOfLoginNameField = "e";
    std::string nameToLogin = "e";
    std::string passwordFieldName = "e";
    qDebug() << "url: " << url << "\n"
             << "nameOfLoginNameField: " << nameOfLoginNameField << "\n"
             << "nameToLogin: " << nameToLogin << "\n"
             << "passwordFieldName: " << passwordFieldName << "\n"
        << "\n";
    //std::unique_ptr<HttpReq> req = std::make_unique<HttpReq>();

    std::unique_ptr<Sender> send = std::make_unique<Sender>(
    url,
    nameOfLoginNameField,
    nameToLogin,
    passwordFieldName);

}
