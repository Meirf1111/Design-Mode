#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Prototype
{
public:
    virtual Prototype* clone() const = 0;
    virtual void printInfo() const = 0;
};

class Person : public Prototype
{
private:
    string Name;
    int Age;
public:
    Person(const string& name, const int age) : Name(name), Age(age) {}
    Prototype* clone() const override {
        return new Person(*this);
    }
    void printInfo() const override {
        cout << "Person - Name: " << Name << ", Age: " << Age << endl;
    }
};

class Infomation : public Prototype
{
private:
    string ID;
    int Weight;
public:
    Infomation(const string& id, const int weight) : ID(id), Weight(weight) {}
    Prototype* clone() const override {
        return new Infomation(*this);
    }
    void printInfo() const override {
        cout << "Infomation - ID: " << ID << ", Weight: " << Weight << endl;
    }
};

// 原型管理器
class PrototypeManager {
private:
    std::unordered_map<std::string, Prototype*> prototypes;

public:
    void registerPrototype(const std::string& name, Prototype* prototype) {
        prototypes[name] = prototype;
    }

    Prototype* clonePrototype(const std::string& name) {
        if (prototypes.count(name)) {
            return prototypes[name]->clone();
        }
        return nullptr;
    }
};



int main() {
    PrototypeManager manager;

    Person per1("Xiaoming", 10);
    manager.registerPrototype("Xiaoming", &per1);


    Infomation info("421182", 100);
    manager.registerPrototype("421182", &info);

    Prototype* clonedA = manager.clonePrototype("Xiaoming");
    if (clonedA != nullptr) {
        clonedA->printInfo();
        delete clonedA;
    }

    Prototype* clonedB = manager.clonePrototype("421182");
    if (clonedB != nullptr) {
        clonedB->printInfo();
        delete clonedB;
    }

    return 0;
}
