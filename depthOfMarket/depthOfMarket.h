//
// Created by nikita on 01.05.2021.
//

#ifndef TESTY_DEPTHOFMARKET_H
#define TESTY_DEPTHOFMARKET_H

#include <iostream>
#include <map>


class depthOfMarket {
public:
    depthOfMarket() {};
    ~depthOfMarket() {};
public:
    int addLine(bool forSale, double price, int volume);
    int changeLine(bool forSale, double price, bool newForSale, double newPrice, int newVolume);
    int deleteLine(bool forSale, double price);
    const std::pair<std::map<double,int>::iterator,bool> findLine(bool forSale, double price);
    const void print();
private:
    std::map<double, int> linesForSale;
    std::map<double, int> linesForPurchase;
};


#endif //TESTY_DEPTHOFMARKET_H
