#include "sender.h"
#include "httpreq.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <thread>
#include <cstring>

bool thread1();
bool thread2();

const char* Sender::char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";

// gotta add 2 threads
Sender::Sender(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName)
{
    qDebug() << "Sender instantiated\n";

    bool success = this->tryPassword(
        url,
        nameOfLoginNameField,
        nameToLogin,
        passwordFieldName,
        0
        );
    if(success){
        qDebug("success!");
    }
}

Sender::~Sender(){
    qDebug() << "Sender destroyed\n";
}

/*
 * gotta implement to check if the req is sucessfull. is done?
 * ---------- remove this coment later
 */
bool Sender::tryPassword(//unfinnished?
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName,
    int startAt)
{
    /*
     *  one time its gonna start from 1 and one time from 0 to make it easyer with 2 threads#
     *  +=2 for 2 threads. one is gonna cover all odd numbers and one all even ones
     */
    for(size_t i = startAt; i <= 18446744073709551614; i += 2)
    {
        this->passwordTry = combination_at_index(i);
        const std::string concatenated = std::string("password try:") + this->passwordTry;
        const char* output = concatenated.c_str();
        qDebug(output);


        HttpReq req(url, nameOfLoginNameField, nameToLogin, passwordFieldName, passwordTry);
        if(req.sendReq())
            return true;
    }
    return false;
}

std::string Sender::combination_at_index(unsigned int index) {
    int base = strlen(char_set);  // Total number of characters in the set
    std::string result;

    // Ensure the index is valid (non-negative)
    if (index < 0) {
        return "Invalid index";
    }

    // Generate the combination string
    while (index >= 0) {
        result = char_set[index % base] + result;  // Get the character from the set
        index = index / base - 1;  // Move to the next "place" in the combination
    }

    return result;
}
