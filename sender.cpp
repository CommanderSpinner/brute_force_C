#include "sender.h"

const char* Sender::char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";

// gotta add 2 threads
Sender::Sender(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName)
{
    qDebug() << "Sender instantiated\n";

    std::vector<std::thread> threads;


    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    /*
    if(this->resultT1 || this->resultT2){
        qDebug("success!");
    }
    */
    /*
    bool success = this->tryPassword(
        url,
        nameOfLoginNameField,
        nameToLogin,
        passwordFieldName,
        0
        );
    */
}

Sender::~Sender(){
    qDebug() << "Sender destroyed\n";
}

void Sender::tryPassword(//unfinnished?
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName,
    size_t countThreads)
{
    for(size_t i = countThreads; i <= 18446744073709551614; i += countThreads)
    {
        this->passwordTry = combination_at_index(i);

        const std::string concatenated = std::string("password try:") + this->passwordTry;
        const char* output = concatenated.c_str();
        qDebug(output);

        HttpReq req(url, nameOfLoginNameField, nameToLogin, passwordFieldName, passwordTry);
        if(req.sendReq())
            this->trySuccess = true;
    }
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
