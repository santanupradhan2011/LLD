#include <iostream>

using namespace std;

//enum class LogLevel {
enum LogLevel {
    DEBUG,
    INFO,
    ERROR
};

class ILogger {
    public:
        virtual void log(const string& msg) = 0;
        virtual ~ILogger() {}
};

class InfoLogger : public ILogger {
    public:
        void log(const string& msg)
        {
            cout<<"INFO : "<<msg<<endl;
        }
};

class ErrorLogger : public ILogger{
    public:
        void log(const string& msg)
        {
            cout<<"ERROR : "<<msg<<endl;
        }
};

class DebugLogger : public ILogger {
    public:
        void log(const string& msg)
        {
            cout << "DEBUG : " << msg << endl;
        }
};

class LoggerFactory {
    public:
        static ILogger* createLogger(LogLevel pLogLevel)
        {
            if(pLogLevel == LogLevel::DEBUG)
                return new DebugLogger();
            if(pLogLevel == LogLevel::INFO)
                 return new InfoLogger();
            if(pLogLevel == LogLevel::ERROR)
                 return new ErrorLogger();
            return nullptr;
        }
};


int main()
{
     ILogger* debugLogger = LoggerFactory::createLogger(LogLevel::DEBUG);
    ILogger* infoLogger = LoggerFactory::createLogger(LogLevel::INFO);
    ILogger* errorLogger = LoggerFactory::createLogger(LogLevel::ERROR);

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}
