#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string Name;
public:
    Person(string name) : Name(name) {};
    void show() {
        cout << "装扮的人是：" << Name << endl;
    }
};


class Finery {
public:
    virtual void show() = 0;
};

class TShirts : public Finery {
public:
    void show() override {
        cout << "T桖 " << endl;
    }
};
class BigTrouser : public Finery {
public:
    void show() override {
        cout << "垮裤 " << endl;
    }
};
class Sneakers : public Finery {
public:
    void show() override {
        cout << "破球鞋 " << endl;
    }
};
class Suit : public Finery {
public:
    void show() override {
        cout << "西装 " << endl;
    }
};
class Tie : public Finery {
public:
    void show() override {
        cout << "领带 " << endl;
    }
};

class WearContext
{
private:
    Person* person = NULL;
    Finery* Fin = NULL;
    int wear_num = 0;
    string str[];
public:
    WearContext(string name, int wear_num, ) {
        person = new Person(name);
        int type = 0;
        switch (type)
        {
        case 0:
            Fin = new TShirts();
            break;
        case 1:
            Fin = new BigTrouser();
            break;
        case 2:
            Fin = new Sneakers();
            break;
        case 3:
            Fin = new Suit();
            break;
        case 4:
            Fin = new Tie();
            break;
        default:
            break;
        }
    };

    void show() {
        Fin->show();
        person->show();
    }

};




int main() {
    WearContext* wc = new WearContext("Mei");
    wc->show();

    return 0;
}