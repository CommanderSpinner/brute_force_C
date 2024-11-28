#include "debugConsole.h"

void debugLog(std::string msg)
{
    std::cout << msg << std::endl;
    qDebug() << msg << "\n";
}
