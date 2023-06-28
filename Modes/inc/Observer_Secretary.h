#ifndef OBSERVER_SECRETARY_H
#define OBSERVER_SECRETARY_H

#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class StockObserver;

class Secretary
{
private:
    string Action;
    vector<StockObserver*> observers;
public:
    Secretary() = default;

    void Attach(StockObserver* observer) {
        observers.push_back(observer);
    }

    void Notify() {
        for (auto it : observers) {
            it->Update();
        }
    }

    void SetAction(string action) {
        this->Action = action;
    }

    string GetAction() {
        return this->Action;
    }

    ~Secretary() = default;
};


#endif