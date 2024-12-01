#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "debugConsole.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <memory>
#include "httpreq.h"
#include "sender.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //std::shared_ptr<Ui::MainWindow> ui = std::make_shared<Ui::MainWindow>();
    ui->setupUi(this);
    this->setWindowTitle("Brute Forcer");
    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Force_clicked()
{
    if(ui == NULL){
        std::cerr << "ui obj is null";
    }

    // Check if text_url is properly initialized
    if (!ui->text_url) {
        std::cerr << "text_url widget is not initialized";
        return;
    }

    qDebug() << "Force button was pressed" << "\n";
    //std::string url = ui->text_nameOfLoginNameField->toPlainText().toStdString();
    std::string url = ui->text_url->toPlainText().toStdString();
    std::string nameOfLoginNameField = "";
    std::string nameToLogin = "";
    std::string passwordFieldName = "";
    qDebug() << " url: " << url << "\n"
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
