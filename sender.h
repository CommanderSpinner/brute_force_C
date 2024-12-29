#ifndef SENDER_H
#define SENDER_H
#include "httpreq.h"
#include <QApplication>
#include "httpreq.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <future>
#include <atomic>
#include <vector>

class Sender
{
private:
    static const char* char_set; // "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";
    HttpReq* req;
    bool trySuccess = false;
    std::string passwordTry;
    std::vector<std::thread> threads;
    size_t rangeOfThreads = 0;
    void tryPassword(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName);
    static std::string combination_at_index(unsigned int index);
    size_t calculateRange();
public:

    Sender(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName
        size_t countThreads);
    ~Sender();
};

#endif // SENDER_H
