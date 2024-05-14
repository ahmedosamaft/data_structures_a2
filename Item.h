//
// Created by AhmedOsama on 5/8/2024.
//

#ifndef DATASTRUCTURES_A2_ITEM_H
#define DATASTRUCTURES_A2_ITEM_H


#include <string>
#include <utility>
#include <iostream>

class Item {
public:
    std::string item_name;
    std::string category;
    int price = 0;
    Item(std::string, std::string, int);
    Item() = default;

    bool operator<(const Item &) const;

    void print();

    friend std::ostream& operator<<(std::ostream& os,const Item& item) {
        os << "Item="<< item.item_name << ", category=" << item.category << ", price=" << item.price << "\n";
        return os;
    }
};

Item::Item(std::string name, std::string category, int price) : item_name(std::move(name)), category(std::move(category)), price(price) {
}

bool Item::operator<(const Item &rhs) const {
    return this->item_name < rhs.item_name;
}

void Item::print() {
    printf("Item=%s, category=%s, price=%d\n",item_name.c_str(),category.c_str(),price);
}

#endif //DATASTRUCTURES_A2_ITEM_H
