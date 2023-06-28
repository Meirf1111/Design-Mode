// #include <iostream>
// #include <string>
// #include <vector>
// #include "ObserverPattern.h"
// #include "../inc/Observer_Secretary.h"
#include <iostream>

#include "../inc/Observer_StockObserver.h"

using namespace std;




int main() {
    Secretary tongzizhe;
    StockObserver weiguancha("魏关姹", &tongzizhe);
    StockObserver Yiguancha("易冠茶", &tongzizhe);

    tongzizhe.Attach(&weiguancha);
    tongzizhe.Attach(&Yiguancha);

    tongzizhe.SetAction("老板回来了！");

    tongzizhe.Notify();

    return 0;
}