#include <iostream>
using namespace std;

// Product（产品）
class Animal {
public:
    virtual void speak() const = 0;
};


// ConcreteProduct（具体产品）
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "The dog says: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "The cat says: Woof!" << std::endl;
    }
};

// Creator（创建者）
class AnimalFactory {
public:
    virtual Animal* CreateAnimal() const = 0;
};

// ConcreteCreator（具体创建者）
class DogFactory : public AnimalFactory {
public:
    Animal* CreateAnimal() const override {
        return new Dog();
    }
};

class CatFactory : public AnimalFactory {
public:
    Animal* CreateAnimal() const override {
       return new Cat();
    }
};




int main() {
    AnimalFactory* dogf = new DogFactory();
    Animal* dog = dogf->CreateAnimal();
    dog->speak();
    AnimalFactory* catf = new CatFactory();
    Animal* cat = catf->CreateAnimal();
    cat->speak();

    delete dogf;
    delete dog;
    delete catf;
    delete cat;
    return 0;
}