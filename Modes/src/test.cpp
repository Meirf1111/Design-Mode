#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Secretary;  // 前向声明 Secretary 类

class StockObserver
{
private:
    string Name;
    Secretary* Sub;  // 使用指针替代具体的类对象
public:
    StockObserver() = default;
    StockObserver(string name, Secretary* sub) : Name(name), Sub(sub) {};
    void Update() {
        cout << Sub->GetAction() << ", " << this->Name << " Close Stock, keep working!" << endl;
    }

    ~StockObserver() = default;
};

class Secretary
{
private:
    string Action;
    vector<StockObserver*> observers;  // 使用指针替代具体的类对象
public:
    Secretary() = default;

    void Attach(StockObserver* observer) {  // 使用指针替代具体的类对象
        observers.push_back(observer);
    }

    void Notify() {
        for (auto it : observers) {
            it->Update();
        }
    }

    void SetAction(string action) {
        this->Action = action;
    }

    // string GetAction() {
    //     return this->Action;
    // }
    string GetAction();

    ~Secretary() = default;
};

string Secretary::GetAction() {
    return this->Action;
}

int main() {
    Secretary secretary;
    StockObserver observer1("Observer 1", &secretary);
    StockObserver observer2("Observer 2", &secretary);

    secretary.Attach(&observer1);
    secretary.Attach(&observer2);

    secretary.SetAction("Important news!");

    secretary.Notify();

    return 0;
}
