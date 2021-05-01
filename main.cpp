#include <iostream>
#include "depthOfMarket/depthOfMarket.h"
#include "perrformanceTools/Timer.h"

int main() {

    auto timer1 = Timer();
    auto a = depthOfMarket();
    timer1.Stop();
    std::cout << "создание сущности стакана" << std::endl;
    auto timer2 = Timer();
    a.addLine(1,1,1);
    timer2.Stop();
    std::cout << "добавление элемента в стакан" << std::endl;

    auto timer3 = Timer();
    a.changeLine(1,1,20);
    timer3.Stop();
    std::cout << "изменение элемента в стакане" << std::endl;

    auto timer4 = Timer();
    a.deleteLine(1,1);
    timer4.Stop();
    std::cout << "удаление элемента из стакана" << std::endl;
    return 0;
}
