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

bool HttpReq::sendReq()
{
    try {
        // Initialisieren von cURLpp
        curlpp::Cleanup cleaner;

        // URL des Formularziels
        std::string url = "http://example.com/formular"; // Setze die Ziel-URL

        // Erstellen des Requests
        curlpp::Easy request;
        request.setOpt(new curlpp::options::Url(url));

        // Formulardaten festlegen
        curlpp::Forms formParts;
        formParts.push_back(new curlpp::FormParts::Content("name", "Max Mustermann"));
        formParts.push_back(new curlpp::FormParts::Content("email", "max@example.com"));

        // Formular zum Request hinzufügen
        request.setOpt(new curlpp::options::HttpPost(formParts));

        // Anfrage ausführen
        request.perform();

        std::cout << "Formular erfolgreich gesendet!" << std::endl;
    } catch (curlpp::RuntimeError &e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    } catch (curlpp::LogicError &e) {
        std::cerr << "Logic Error: " << e.what() << std::endl;
    }

    return true;
}
