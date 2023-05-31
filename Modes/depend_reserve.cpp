#include <iostream>
#include <string>

using namespace std;

// 抽象类(接口)
class Ilogger {
public:
    virtual void log(const string& message) = 0;
};

// 高层模块依赖于抽象类（接口）
class MyService {
private:
    Ilogger* Logger;

public:
    MyService(Ilogger* logger) : Logger(logger) {}

    void doSomething() {
        Logger->log("Doing something...");
    }
};

// 具体实现类
class ConsoleLogger : public Ilogger {
public:
    void log(const std::string& message) override {
        std::cout << "Console Logger: " << message << std::endl;
    }
};



int main() {
    ConsoleLogger consoleLogger;

    // 创建高层模块对象，并将具体实现对象传递给它
    MyService myService(&consoleLogger);

    // 调用高层模块的方法
    myService.doSomething();



    return 0;
}