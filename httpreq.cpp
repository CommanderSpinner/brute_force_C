#include "httpreq.h"
#include <QApplication>

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

        // Anfrage ausführen
        request.perform();

        qDebug() << "request send" << std::endl;
    } catch (curlpp::RuntimeError &e) {
        qDebug() << "Runtime Error: " << e.what() << std::endl;
        return false;
    } catch (curlpp::LogicError &e) {
        qDebug() << "Logic Error: " << e.what() << std::endl;
        return false;
    }

    return true;
}
