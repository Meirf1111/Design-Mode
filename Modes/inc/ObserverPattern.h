#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StockObserver;
// class Secretary;




class Secretary
{
private:
    string Action;
    vector<StockObserver*> observers;
public:
    Secretary() = default;

    void Attach(StockObserver* observer) {
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

    string GetAction() {
        return this->Action;
    }

    ~Secretary() = default;
};

class StockObserver
{
private:
    string Name;
    Secretary* Sub;
public:
    StockObserver() = default;
    StockObserver(string name, Secretary* sub) : Name(name), Sub(sub) {};
    void Update() {
        // cout << Sub->GetAction() << ", " << this->Name << " Close Stock, keep working!" << endl;
    }


    ~StockObserver() = default;
};

void StockObserver::Update() {
    cout << Sub->GetAction() << ", " << this->Name << " Close Stock, keep working!" << endl;
}