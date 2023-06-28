#include <iostream>
#include <string>
using namespace std;

class Resume_Prototype {
    virtual Resume_Prototype* clone() const = 0;
    virtual void SetInfomation(string name, string sex, string timeArea, string company, string workdata, int age) = 0;
    virtual void Display() const = 0;
};

class WorkExperience {
private:
    string WorkData;
    string Company;
public:
    WorkExperience() = default;
    void SetInfo(string workdata, string company) {
        this->WorkData = workdata;
        this->Company = company;
    }
    string* GetInfo() {
        static string str[] = {};
        str[0] = this->WorkData;
        str[1] = this->Company;
        cout << "GetInfo" << "WorkData:" << str[0] << "\tCompany:" << str[1] << endl;
        cout << "GetInfo1" << "this->WorkData:" << this->WorkData << "\tthis->Company:" << this->Company << endl;
        // string* str = new string[2];
        // str[0] = this->WorkData;
        // str[1] = this->Company;
        return str;
    }
};

class Resume : public Resume_Prototype
{
private:
    string Name, Sex, TimeArea;
    WorkExperience* work; 
    int Age;
public:
    Resume() = default;

    void SetInfomation(string name, string sex, string timeArea, string company, string workdata, int age) override {
        this->Name      = name;
        this->Sex       = sex;
        this->TimeArea  = timeArea;
        this->Age       = age;

        work = new WorkExperience();
        work->SetInfo(workdata, company);
    }

    void Display() const override {
        string* str = work->GetInfo();
        cout << "Name:" << Name << " \tSex:" << Sex << " \tTimeArea:" << TimeArea << " \tCompany:" << str[1] << " \tWorkData:" << str[0] << " \tAge:" << Age << endl;
    }

    Resume_Prototype* clone() const override {
        return new Resume(*this);
    }
    ~Resume() {
        delete work;
    }
};

int main() {
    Resume a;
    a.SetInfomation("ZhangSan", "Man", "1999-2000", "Neusoft", "A", 20);
    Resume* b = dynamic_cast<Resume*>(a.clone());
    if (b) {
        b->SetInfomation("LiSi", "Man", "1999-2010", "Tencent", "B", 40);
    } else {
        cout << "dynamic_cast failed" << endl;
    }
    Resume* c = dynamic_cast<Resume*>(a.clone());
    if (c) {
        c->SetInfomation("Mei", "Man", "2022-2023", "Ali", "C", 25);
    } else {
        cout << "dynamic_cast failed" << endl;
    }

    Resume d;
    d.SetInfomation("Han", "WoMan", "2022-2023", "aa", "D", 25);

    a.Display();
    b->Display();
    c->Display();
    d.Display();
    delete b;
    delete c;

    return 0;
}

// #include <iostream>
// using namespace std;

// int ReturnNum(int temp) {
//     static int num = 0;  // 静态数组，在函数调用结束后仍然有效
//     num += temp ;
//     return num;
// }

// int main() {
//     int num1 = ReturnNum(1);
//     int num2 = ReturnNum(10);

//     cout << "num1: " << num1 << "  num2:" << num2 << endl;
//     return 0;
// }