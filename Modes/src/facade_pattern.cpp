#include <iostream>
using namespace std;

class Stock {
public:
    virtual void Sell() = 0;
    virtual void Buy() = 0;
};

class Stock1 : public Stock {
public:
    void Sell() override {
        cout << "Sell stock1!" << endl;
    }
    void Buy() override {
        cout << "Buy stock1!" << endl;
    }
};

class Stock2 : public Stock {
public:
    void Sell() override {
        cout << "Sell stock2!" << endl;
    }
    void Buy() override {
        cout << "Buy stock2!" << endl;
    }
};

class Stock3 : public Stock {
public:
    void Sell() override {
        cout << "Sell stock3!" << endl;
    }
    void Buy() override {
        cout << "Buy stock3!" << endl;
    }
};

class NationalDebt1 : public Stock {
public:
    void Sell() override {
        cout << "Sell NationalDebt1!" << endl;
    }
    void Buy() override {
        cout << "Buy NationalDebt1!" << endl;
    }
};

class Realty1 : public Stock {
public:
    void Sell() override {
        cout << "Sell Realty1!" << endl;
    }
    void Buy() override {
        cout << "Buy Realty1!" << endl;
    }
};

class Fund {
private:
    // Stock* stock = NULL;

    Stock1 stock1;
    Stock2 stock2;
    Stock3 stock3;
    NationalDebt1 nationdebt;
    Realty1 realty;
public:
    Fund() = default;

    void BuyFund() {
        stock1.Buy();
        stock2.Buy();
        stock3.Buy();
        nationdebt.Buy();
        realty.Buy();
    }
    void SellFund() {
        stock1.Sell();
        stock2.Sell();
        stock3.Sell();
        nationdebt.Sell();
        realty.Sell();
    }
};


int main() {
    Fund jijin;
    jijin.BuyFund();
    jijin.SellFund();


    return 0;
}