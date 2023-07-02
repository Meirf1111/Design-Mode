// 抽象工厂模式
#include "../inc/AbstractFactory.h"

int main() {
    User user;
    IFactory* factory = new AccessServerFactory();
    IUser* iu = factory->CreateUser();;

    iu->Insert(user);
    iu->GetUser(1);

    Department department;
    IFactory* factory_department = new SqlServerFactory();
    IDepartment* id = factory_department->CreateDepartment();;

    id->Insert(department);
    id->GetDepartment(1);

    return 0;
}