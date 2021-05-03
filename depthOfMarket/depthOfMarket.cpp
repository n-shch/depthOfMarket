//
// Created by nikita on 01.05.2021.
//

#include "depthOfMarket.h"

// adds line to depthOfMarket by given parameters: forSale, price, volume
int depthOfMarket::addLine(bool forSale, double price, int volume) {
    if (forSale) {
        auto element = linesForSale.insert(std::make_pair(price, volume));
        if (element.second == false) {
            std::cout << "no new line was insert:";
            std::cout << " line already exists with the price of " << element.first->first << std::endl;
            return -1;
        }
        return 0;
    }
    auto element = linesForPurchase.insert(std::make_pair(price, volume));
    if (element.second == false) {
        std::cout << "no new line was insert:";
        std::cout << " line already exists with a price of " << element.first->first << std::endl;
        return -1;
    }
    return 0;
};

//  changes line by given parameters: forSale, price
int depthOfMarket::changeLine(bool forSale, double price, bool newForSale, double newPrice, int newVolume) {
    if (forSale != newForSale || newPrice != newPrice) {
        this->deleteLine(forSale, price);
        this->addLine(newForSale, newPrice, newVolume);
        return 0;
    }
    if (forSale) {
        if (linesForSale.find(price) != linesForSale.end()) {
            linesForSale[price] = newVolume;
            return 0;
        }
    }
    if (linesForPurchase.find(price) != linesForPurchase.end()) {
        linesForPurchase[price] = newVolume;
        return 0;
    }
    return -1;
};

// Deletes line by given parameters: forSale and price
int depthOfMarket::deleteLine(bool forSale, double price) {
    if (forSale) {
        if (linesForSale.find(price) != linesForSale.end()) {
            linesForSale.erase(price);
            return 0;
        }
    }
    if (linesForPurchase.find(price) != linesForPurchase.end()) {
        linesForPurchase.erase(price);
        return 0;
    }
    return -1;
};

//  prints all lines in the depthOfMarket
const void depthOfMarket::print() {
    for (std::map<double, int>::reverse_iterator it = linesForSale.rbegin(); it != linesForSale.rend(); ++it) {
        std::cout << "Продажа " << (*it).first << " " << (*it).second << std::endl;
    }
    for (std::map<double, int>::reverse_iterator it = linesForPurchase.rbegin(); it != linesForPurchase.rend(); ++it) {
        std::cout << "Покупка " << (*it).first << " " << (*it).second << std::endl;
    }
    std::cout << "________________________________________________" << std::endl;
};

//  Finds line in DepthOfMarket by given parameters: forSale, price
const std::pair<std::map<double,int>::iterator,bool> depthOfMarket::findLine(bool forSale, double price) {
    if (forSale) {
        auto element = linesForSale.find(price);
        if (element != linesForSale.end()) {
            return std::make_pair(element, true);
        }
        return std::make_pair(element, false);
    }
    auto element = linesForPurchase.find(price);
    if (element != linesForPurchase.end()) {
        return std::make_pair(element, true);
    }
    return std::make_pair(element, false);
}
