#include <iostream>
#include <string>
#include <list>
using namespace std;

class Subject;

class Observer {
protected:
    string Name;
    Subject* Sub;
public:
    Observer(const string name, Subject* sub) : Name(name), Sub(sub) {}
};

class StockObserver : public Observer {
public:
    StockObserver(const string name, Subject* sub) : Observer(name, sub){}
    void CloseStockUpdate() {
        cout << Sub->GetSubjectState() << ", " << this->Name << " Close Stock, keep working!" << endl;
    }
};
class NBAObserver : public Observer {
public:
    NBAObserver(const string name, Subject* sub) : Observer(name, sub){}
    void CloseNBAUpdate() {
        cout << Sub->GetSubjectState() << ", " << this->Name << " Close NBA, keep working!" << endl;
    }
};

class Subject {
protected:
    string SubjectState;
public:
    virtual void Notify() = 0;
    virtual void SetSubjectState(const string subjectstate) = 0;
    virtual string GetSubjectState() const = 0;
};

class Boss : public Subject {
private:
    string Action;
    typedef void (*Update)();
    Update update;
public:
    Boss() {
        this->update = NULL;
    }

    void SetUpdate(Update update) {
        this->update = update;
    }

    void Notify() override {
        if (this->update == NULL) {
            cout << "update is NULL" << endl;
            return;
        }

        update();
    }
    void SetSubjectState(const string subjectstate) override {
        this->SubjectState = subjectstate;
    }
    string GetSubjectState() const override {
        return this->SubjectState;
    }
};




int main() {
    Boss huhansan;
    StockObserver weiguancha("Weiguancha", &huhansan);
    StockObserver yiguancha("yiguancha", &huhansan);

   

    huhansan.SetSubjectState("我胡汉三回来了");

    huhansan.SetUpdate(&weiguancha.CloseStockUpdate);


    huhansan.Notify();

    return 0;
}