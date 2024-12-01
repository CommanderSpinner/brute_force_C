#ifndef SENDER_H
#define SENDER_H
#include "httpreq.h"
#include <QApplication>

class Sender
{
private:
    HttpReq* req;
    std::string passwordTry;
public:
    Sender();
};

#endif // SENDER_H
