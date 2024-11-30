#ifndef SENDER_H
#define SENDER_H
#include "httpreq.h"

class Sender
{
private:
    HttpReq req;
public:
    Sender(HttpReq* req);
};

#endif // SENDER_H
