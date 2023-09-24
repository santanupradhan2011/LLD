#include <iostream>

using namespace std;

enum  LogLevel {
    DEBUG,
    INFO,
    ERROR
};



class ILogger {
    public:
        virtual void log(const string& msg) = 0;
        virtual ~ILogger() {}
};



class ILoggerFactory {
    public:
        virtual ILogger* createLogger() = 0;
};

class DebugLogger : public ILogger {
    public:
        void log(const string& msg)
        {
            cout << "DEBUG : " << msg << endl;
        }
};

class DebugLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new DebugLogger();
        }
};


class ErrorLogger : public ILogger{
    public:
        void log(const string& msg)
        {
            cout<<"ERROR : "<<msg<<endl;
        }
};

class ErrorLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new ErrorLogger();
        }
};

class InfoLogger : public ILogger {
    public:
        void log(const string& msg)
        {
            cout<<"INFO : "<<msg<<endl;
        }
};

class InfoLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new InfoLogger();
        }
};


int main()
{
    ILoggerFactory* loggerFactory1 = new InfoLoggerFactory;
    ILogger* infoLogger = loggerFactory1->createLogger();

    ILoggerFactory* loggerFactory2 = new ErrorLoggerFactory;
    ILogger* errorLogger = loggerFactory2->createLogger();

    ILoggerFactory* loggerFactory3 = new DebugLoggerFactory;
    ILogger* debugLogger = loggerFactory3->createLogger();

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}
