#include <iostream>
#include "depthOfMarket/depthOfMarket.h"

int main() {
    auto a = depthOfMarket();
    a.addLine(1,1,1);

    a.addLine(0,1,1);
    a.print();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
