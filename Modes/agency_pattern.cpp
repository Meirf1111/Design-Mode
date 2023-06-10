#include <iostream>
#include <string>
using namespace std;

class SchoolGirl {
private:
    string Name;
public:
    SchoolGirl() = default;
    SchoolGirl(string name) : Name(name) {};
    string getName() {
        return this->Name;
    }
};

class Givegift {
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

class Pursuit : public Givegift {
private:
    SchoolGirl MM;
public:
    Pursuit() = default;
    Pursuit(SchoolGirl mm) : MM(mm) {};

    void GiveDolls() override {
        cout << MM.getName() << ", 送你洋娃娃" << endl;
    }
    void GiveFlowers() override {
        cout << MM.getName() << ", 送你花儿" << endl;
    }
    void GiveChocolate() override {
        cout << MM.getName() << ", 送你巧克力" << endl;
    }
};


class Proxy : public Givegift{
private:
    Pursuit* GG;
public:
    Proxy() = default;
    Proxy(Pursuit* gg) : GG(gg) {};

    void GiveDolls() override {
        GG->GiveDolls();
    }
    void GiveFlowers() override {
        GG->GiveFlowers();
    }
    void GiveChocolate() override {
        GG->GiveChocolate();
    }
};


int main() {
    SchoolGirl* hw = new SchoolGirl("hw");
    // Pursuit* Mei = new Pursuit(*hw);

    Proxy * daili = new Proxy(new Pursuit(*hw));
    
    daili->GiveDolls();
    daili->GiveFlowers();
    daili->GiveChocolate();

    return 0;
}