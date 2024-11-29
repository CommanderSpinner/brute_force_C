#include "httpreq.h"

HttpReq::httpReq(std::stirng req)
{
    this->request = req;
    if(!this->sendReq())
    {
        qDebug() << "failed to send request!" << "\n";
    }
}
bool HttpReq::sendReq()
{


    return true;
}
