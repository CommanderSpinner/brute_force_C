#ifndef HTTPREQ_H
#define HTTPREQ_H
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Exception.hpp>
#include <iostream>
#include <string>

class HttpReq
{
public:
    HttpReq(std::string req);
    HttpReq();
    void setRequest(std::string req);
    HttpReq setRequest();
private:
    std::string request;
    bool sendReq();
};

#endif // HTTPREQ_H
