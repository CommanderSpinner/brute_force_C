#include "sender.h"
#include "httpreq.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <thread>
#include <cstring>

const char* Sender::char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";

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
        passwordFieldName
        );
    if(success){
        qDebug("success!");
    }
}

Sender::~Sender(){
    qDebug() << "Sender destroyed\n";
}

/*
gotta implement to check if the req is sucessfull
*/
bool Sender::tryPassword(//unfinnished
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName)
{
    for(size_t i = 0; i <= 18446744073709551614; i++)
    {
        this->passwordTry = combination_at_index(i); // implement logic later

        HttpReq req(url, nameOfLoginNameField, nameToLogin, passwordFieldName, passwordTry);
        req.sendReq()
    }
    return true;
}

std::string Sender::combination_at_index(int index) {
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
