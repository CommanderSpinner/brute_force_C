#include "httpreq.h"
#include <QApplication>

HttpReq::HttpReq(std::string req)
{
    this->request = req;
    if(!this->sendReq())
    {
        qDebug() << "failed to send request!" << "\n";
        return;
    }


}
bool HttpReq::sendReq()
{


    return true;
}
