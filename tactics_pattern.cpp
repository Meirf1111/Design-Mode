#include <iostream>
#include <cmath>

using namespace std;

class CashSuper {
public:
    virtual double acceptCash(double money) = 0;
};

class CashNormal :  public CashSuper {
public:
    double acceptCash(double money) override {
        return money;
    }
};

class CashRebate :  public CashSuper {
private:
    double MoneyRebate = 1;
public:
    CashRebate(double moneyRebate) : MoneyRebate(moneyRebate) {}

    double acceptCash(double money) override {
        return money * MoneyRebate;
    }
};

class CashReturn : public CashSuper {
private:
    double MoneyCondition, MoneyNum;
public:
    CashReturn(double moneycondition, double moneynum) : MoneyCondition(moneycondition), MoneyNum(moneynum) {}

    double acceptCash(double money) override {
        double result = money;
        if (money > MoneyCondition) result = money - floor(money / MoneyCondition) * MoneyNum;
        return result;
    }
};

// 工厂类
// class CashFactory {
// public:
//     static CashSuper* CreateCashSuper(int type) {
//         switch (type)
//         {
//         case 0:
//             return new CashNormal();
//             break;
//         case 1:
//             return new CashRebate(0.8);
//             break;
//         case 2:
//             return new CashReturn(300, 100);
//             break;
//         default:
//             return NULL;
//             break;
//         }

//     }
// };

class CashContext {
private:
    CashSuper* CS = NULL;
public:
    CashContext(int type) {
        switch (type)
        {
        case 0:
            CS = new CashNormal();
            break;
        case 1:
            CS = new CashRebate(0.6);
            break;
        case 2:
            CS = new CashReturn(300, 100);
            break;
        default:
            break;
        }
    }
    
    double GetMoney(double money) {
        return CS->acceptCash(money);
    }
};



int main() {
    double totalAmount = 1000;
    cout << "购物总金额为：" << totalAmount << endl;;
    int type = 1;
    CashContext cc(0);
    
    double total = cc.GetMoney(totalAmount);



    cout << "预付的总金额为：" << total << endl;;



    return 0;
}