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
    HttpReq(
        std::string url,
        std::string nameOfLoginNameField,
        std::string nameToLogin,
        std::string passwordFieldName,
        std::string passwordToLogin
        );
    bool sendReq();
private:
    std::string url;
    std::string nameOfLoginNameField;
    std::string nameToLogin;
    std::string passwordFieldName;
    std::string passwordToLogin;

};

#endif // HTTPREQ_H
