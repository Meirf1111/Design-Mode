#include <iostream>
using namespace std;

class Person
{
private:
    string Head;
    string Body;
    string ArmLeft;
    string ArmRight;
    string LegLeft;
    string LegRight;
public:
    Person() = default;
    ~Person() = default;

    void setHead(const string& head) {
        this->Head = head;
    }
    void setBody(const string& body) {
        this->Body = body;
    }
    void setArmLeft(const string& armleft) {
        this->ArmLeft = armleft;
    }
    void setArmRight(const string& armright) {
        this->ArmRight = armright;
    }
    void setLegLeft(const string& legleft) {
        this->LegLeft = legleft;
    }
    void setLegRight(const string& legright) {
        this->LegRight = legright;
    }

    void show() {
        cout << Head << endl;
        cout << "Head:" << Head << endl;
        cout << "Body:" << Body << endl;
        cout << "ArmLeft:" << ArmLeft << endl;
        cout << "ArmRight:" << ArmRight << endl;
        cout << "LegLeft:" << LegLeft << endl;
        cout << "LegRight:" << LegRight << endl;
        cout << endl;
    }
};



class PersonBuilder
{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildArmLeft() = 0;
    virtual void BuildArmRight() = 0;
    virtual void BuildLegLeft() = 0;
    virtual void BuildLegRight() = 0;
    virtual Person* getPerson() = 0;
};

class PersonThinBuilder : public PersonBuilder
{
private:
    Person* person = new Person();
public:
    ~PersonThinBuilder() {
        delete person;
    }
    void BuildHead() override {
        person->setHead("thin person head");
    }
    void BuildBody() override {
        person->setBody("thin person Body");
    }
    void BuildArmLeft() override {
        person->setArmLeft("thin person ArmLeft");
    }
    void BuildArmRight() override {
        person->setArmRight("thin person ArmRight");
    }
    void BuildLegLeft() override {
        person->setLegLeft("thin person LegLeft");
    }
    void BuildLegRight() override {
        person->setLegRight("thin person LegRight");
    }
    Person* getPerson() override {
        return person;
    };

};

class PersonFatBuilder : public PersonBuilder
{
private:
    Person* person = new Person();
public:
    void BuildHead() override {
        person->setHead("fat person head");
    }
    void BuildBody() override {
        person->setBody("fat person Body");
    }
    void BuildArmLeft() override {
        person->setArmLeft("fat person ArmLeft");
    }
    void BuildArmRight() override {
        person->setArmRight("fat person ArmRight");
    }
    void BuildLegLeft() override {
        person->setLegLeft("fat person LegLeft");
    }
    void BuildLegRight() override {
        person->setLegRight("fat person LegRight");
    }
    Person* getPerson() override {
        return person;
    };
};

class PersonDirector {
private:
    PersonBuilder* Pb = NULL;
    int type = 0;
public:
    PersonDirector() = default;
    PersonDirector(int type) {
        this->type = type;
    }

    void SelectPerson() {
        switch (this->type)
        {
        case 1:
            Pb = new PersonThinBuilder();
            break;
        case 2:
            Pb = new PersonFatBuilder();
            break;
        default:
            break;
        }
    }

    void SelectType(int type) {
        this->type = type;
    }

    Person* CreatePerson() {
        if (this->Pb == NULL) {
            cout << "Pb is NULL!" << endl;
            return NULL;
        }

        Pb->BuildArmLeft();
        Pb->BuildBody();
        Pb->BuildArmLeft();
        Pb->BuildArmRight();
        Pb->BuildLegLeft();
        Pb->BuildLegRight();

        return Pb->getPerson();
    }

    ~PersonDirector() {
        delete Pb;
    }
};



int main() {
    PersonDirector Pb1(1);
    PersonDirector Pb2(2);
    PersonDirector pb3;
    
    Person* per1 = Pb1.CreatePerson();
    Person* per2 = Pb2.CreatePerson();
    Person* per3 = pb3.CreatePerson();

    Pb1.SelectPerson();
    Pb1.CreatePerson();

    Pb2.SelectPerson();
    Pb2.CreatePerson();

    pb3.CreatePerson();

    pb3.SelectType(1);
    pb3.SelectPerson();
    pb3.CreatePerson();

    per1 = Pb1.CreatePerson();
    per2 = Pb2.CreatePerson();
    per3 = pb3.CreatePerson();

    per1->show();
    per2->show();
    per3->show();

    delete per1;
    delete per2;
    delete per3;

    return 0;
}