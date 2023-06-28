#ifndef OBSERVER_STOCKOBSERVER_H
#define OBSERVER_STOCKOBSERVER_H

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Observer_Secretary.h"

using namespace std;


class StockObserver
{
private:
    string Name;
    Secretary* Sub;
public:
    StockObserver() = default;
    StockObserver(string name, Secretary* sub) : Name(name), Sub(sub) {};
    void Update() {
        cout << Sub->GetAction() << ", " << this->Name << " Close Stock, keep working!" << endl;
    }


    ~StockObserver() = default;
};

void Secretary::Notify() {
        for (auto it : observers) {
            it->Update();
        }
    }

#endif