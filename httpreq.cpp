#include "httpreq.h"
#include <QApplication>
#include <cstdio>
#include <cstring>

HttpReq::HttpReq(
    std::string url,
    std::string nameOfLoginNameField,
    std::string nameToLogin,
    std::string passwordFieldName,
    std::string passwordToLogin
    )
{
    this->url = url;
    this->nameOfLoginNameField = nameOfLoginNameField;
    this->nameToLogin = nameToLogin;
    this->passwordFieldName = passwordFieldName;
    this->passwordToLogin = passwordToLogin;

    qDebug() << "Http request instantiated\n";
}

HttpReq::~HttpReq()
{
    qDebug() << "Request destroyed";
}

bool HttpReq::sendReq() // unfinnished
{
    try
    {
        // Initialising of cURLpp
        curlpp::Cleanup cleaner;

        // create req
        curlpp::Easy request;
        request.setOpt(new curlpp::options::Url(this->url));

        // set form data
        curlpp::Forms formParts;

        //unfinnished
        formParts.push_back(new curlpp::FormParts::Content("name", "Max Mustermann"));
        formParts.push_back(new curlpp::FormParts::Content("email", "max@example.com"));

        request.setOpt(new curlpp::options::HttpPost(formParts));

        std::ostringstream responseStream;
        request.setOpt(new curlpp::options::WriteStream(&responseStream));


        // Anfrage ausführen
        request.perform();

        // Analyze the response
        std::string response = responseStream.str();

        qDebug() << "request send\n";
        return response.find("Login successful") != std::string::npos;
    } catch (curlpp::RuntimeError &e) {
        std::string msg = "Runtime Error:" + (std::string)(e.what()) + "\n";
        qDebug(msg.c_str());
        return false;
    } catch (curlpp::LogicError &e) {
        std::string msg = "Runtime Error:" + (std::string)(e.what()) + "\n";
        qDebug(msg.c_str());
        return false;
    }

    return false;
}
