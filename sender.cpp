#include "sender.h"
#include <QApplication>
#include <iostream>
#include <string>

Sender::Sender(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName)
{
    qDebug() << "Sender instantiated\n";
    this->tryPassword(
        url,
        nameOfLoginNameField,
        nameToLogin,
        passwordFieldName);
}

Sender::~Sender(){
    qDebug() << "Sender destroyed\n";
}


bool Sender::tryPassword(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName)
{
    this->passwordTry = ""; // implement logic later

    HttpReq req(url, nameOfLoginNameField, nameToLogin, passwordFieldName);

    if(!req.sendReq()){
        qDebug() << "sometihng went wrong while sending the request!\n";
        return false;
    }

    return true;
}
