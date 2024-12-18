#ifndef SENDER_H
#define SENDER_H
#include "httpreq.h"
#include <QApplication>

class Sender
{
private:
    static const char* char_set; // "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";
    HttpReq* req;
    std::string passwordTry;
    bool tryPassword(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName,
        int startAt);
    static std::string combination_at_index(int index);
public:
    Sender(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName);
    ~Sender();
};

#endif // SENDER_H
