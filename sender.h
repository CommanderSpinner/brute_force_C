#ifndef SENDER_H
#define SENDER_H
#include "httpreq.h"
#include <QApplication>

class Sender
{
private:
    static const char* char_set; // "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";
    HttpReq* req;
    bool trySuccess = false;
    std::string passwordTry;
    void tryPassword(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName,
        int startAt,
        countThreads);
    static std::string combination_at_index(unsigned int index);
public:

    Sender(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName, countThreads);
    ~Sender();
};

#endif // SENDER_H
