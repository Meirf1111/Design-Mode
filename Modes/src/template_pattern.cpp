#include <iostream>
#include <string>

using namespace std;

class TestPaper {
public:
    TestPaper() = default;

    void TestQusetion1() {
        cout << "Question1：xxx" << endl;
        cout <<  "Answer1: " << Answer1() << endl;
    }
    virtual string Answer1() {
        return "";
    }

    void TestQusetion2() {
        cout << "Question2：xxx" << endl;
        cout <<  "Answer2: " << Answer2() << endl;
    }
    virtual string Answer2() {
        return "";
    }

    void TestQusetion3() {
        cout << "Question3：xxx" << endl;
        cout <<  "Answer3: " << Answer3() << endl;
    }
    virtual string Answer3() {
        return "";
    }

};
class TestPaperA : public TestPaper {
public:
    string Answer1() override {
        return "A";
    }
    string Answer2() override {
        return "C";
    }
    string Answer3() override {
        return "D";
    }
};
class TestPaperB : public TestPaper {
public:
    string Answer1() override {
        return "D";
    }
    string Answer2() override {
        return "C";
    }
    string Answer3() override {
        return "B";
    }
};

int main() {
    TestPaper* stu1 = new TestPaperA();
    stu1->TestQusetion1();
    stu1->TestQusetion2();
    stu1->TestQusetion3();
    TestPaper* stu2 = new TestPaperB();
    stu2->TestQusetion1();
    stu2->TestQusetion2();
    stu2->TestQusetion3();

    delete stu1;
    delete stu2;


    return 0;
}