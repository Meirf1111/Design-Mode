// 抽象工厂模式
#ifndef ABSTRACTFACTORY
#define ABSTRACTFACTORY

#pragma once

#include <iostream>
#include <string>
using namespace std;

// User
class User {
private:
    int _id;
    string _name;
public:
    User() = default;
    User(int id, string name) : _id(id), _name(name) {};

    void SetId(const int id) {
        this->_id = id;
    }
    int GetId() const{
        return this->_id;
    }

    void SetName(const string name) {
        this->_name = name;
    }
    string GetName() const{
        return this->_name;
    }

    ~User() = default;
};

class IUser {
public:
    virtual void Insert(User user) = 0;
    virtual User* GetUser(int id) = 0;
};

class SqlServerUser : public IUser {
public:
    void Insert(User user) override {
        cout << "在SQL server中给User表增加一条记录！" << endl;
    }
    User* GetUser(int id) override {
        cout << "在SQL server中给User表增加一条记录！" << endl;
        return NULL;
    }
};

class AccessServerUser : public IUser {
public:
    void Insert(User user) override {
        cout << "在Access server中给User表增加一条记录！" << endl;
    }
    User* GetUser(int id) override {
        cout << "在Access server中给User表增加一条记录！" << endl;
        return NULL;
    }
};

// Department
class Department {
private:
    int _id;
    string _name;
public:
    Department() = default;
    Department(int id, string name) : _id(id), _name(name) {};

    void SetId(const int id) {
        this->_id = id;
    }
    int GetId() const{
        return this->_id;
    }

    void SetName(const string name) {
        this->_name = name;
    }
    string GetName() const{
        return this->_name;
    }

    ~Department() = default;
};

class IDepartment {
public:
    virtual void Insert(Department department) = 0;
    virtual Department* GetDepartment(int id) = 0;
};

class SqlServerDepartment : public IDepartment {
public:
    void Insert(Department department) override {
        cout << "在SQL server中给Department表增加一条记录！" << endl;
    }
    Department* GetDepartment(int id) override {
        cout << "在SQL server中给Department表增加一条记录！" << endl;
        return NULL;
    }
};

class AccessServerDepartment : public IDepartment {
public:
    void Insert(Department department) override {
        cout << "在Access server中给Department表增加一条记录！" << endl;
    }
    Department* GetDepartment(int id) override {
        cout << "在Access server中给Department表增加一条记录！" << endl;
        return NULL;
    }
};

class IFactory {
public:
    virtual IUser* CreateUser() = 0;
    virtual IDepartment* CreateDepartment() = 0;
};

class SqlServerFactory : public IFactory {
public:
    IUser* CreateUser() override {
        return new SqlServerUser();
    }

    IDepartment* CreateDepartment() override {
        return new SqlServerDepartment();
    }
};

class AccessServerFactory : public IFactory {
public:
    IUser* CreateUser() override {
        return new AccessServerUser();
    }
    IDepartment* CreateDepartment() override {
        return new AccessServerDepartment();
    }
};

#endif