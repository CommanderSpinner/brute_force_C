#ifndef SENDER_H
#define SENDER_H
#include "httpreq.h"
#include <QApplication>

class Sender
{
private:
    static bool tryingPassword = false;
    HttpReq* req;
    std::string passwordTry;
    bool tryPassword(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName);
public:
    Sender(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName);
    ~Sender();
};

#endif // SENDER_H
