#include "sender.h"

Sender::Sender(HttpReq* req)
{
    this->req = req;
    qDebug << "Sender instantiated\n";
}
