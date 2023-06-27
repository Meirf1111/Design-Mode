#include <iostream>
#include <string>

using namespace std;

// Product
class Pizza {
private:
    string dough;
    string sauce;
    string topping;
public:
    Pizza() = default;
    ~Pizza() = default;

    void setDough(const std::string& dough) {
        this->dough = dough;
    }

    void setSauce(const std::string& sauce) {
        this->sauce = sauce;
    }

    void setTopping(const std::string& topping) {
        this->topping = topping;
    }

    void showPizza() const {
        cout << "Pizza with " << dough << " dough, " << sauce << " sauce, and " << topping << " topping." << endl;
    } 
};

// Builder（建造者）
class PizzaBuilder {
private:
    /* data */
public:
    virtual ~PizzaBuilder() {}

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza* getPizza() = 0;
};

// ConcreteBuilder（具体建造者）
class MargheritaPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza->setDough("thin crust");
    }

    void buildSauce() override {
        pizza->setSauce("tomato");
    }

    void buildTopping() override {
        pizza->setTopping("mozzarella cheese");
    }

    Pizza* getPizza() override {
        return pizza;
    }

private:
    Pizza* pizza = new Pizza();
};

// Director（指挥者）
class PizzaDirector {
public:
    Pizza* createPizza(PizzaBuilder* builder) {
        builder->buildDough();
        builder->buildSauce();
        builder->buildTopping();
        return builder->getPizza();
    }
};







int mian() {
    PizzaBuilder* builder = new MargheritaPizzaBuilder();
    PizzaDirector director;
    Pizza* pizza = director.createPizza(builder);
    pizza->showPizza();

    delete pizza;
    delete builder;


    return 0;
}