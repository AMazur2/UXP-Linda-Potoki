//author: Patryk Karbownik

#ifndef UXP_LINDA_POTOKI_LOGGER_H
#define UXP_LINDA_POTOKI_LOGGER_H


#include <string>
#include <sys/stat.h>
#include <fstream>

using namespace std;

class Logger {
private:
    string loggerName;
    const char* loggerDir = "logs";
    ofstream streamToLoggerFile;
    void createLoggerFile();
    void writeDate(char *date);

public:
    Logger(string loggerName);
    void write(string s);
    void write(string s, char *date);
    void close();
    ~Logger();
};


#endif //UXP_LINDA_POTOKI_LOGGER_H
