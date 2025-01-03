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
    //std::unique_ptr<int[]> heapArray(new int[]);
    void tryPassword(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName,
        size_t countThreads);
    static std::string combination_at_index(unsigned int index);
public:

    Sender(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName);
    ~Sender();
};

#endif // SENDER_H
