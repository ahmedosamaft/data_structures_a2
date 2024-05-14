#include <iostream>
#include <functional>
#include "BinarySearchTree.h"
#include "Item.h"
#include "Heap.h"

struct comparer {
    bool operator()(Item &a, Item &b) const {
        return a.price < b.price;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    BinarySearchTree<Item,comparer> bs;
    bs.Add(Item("d","c1",51));
    bs.Add(Item("b","c1",54));
    bs.Add(Item("a","c1",40));
    bs.Add(Item("c","c1",11));
    bs.ShowAscending();
    std::cout << std::endl;
    bs.ShowDescending();
    Item arr[] {Item("d","c1",51),
                Item("a","c1",40),
                Item("c","c1",11),
                Item("b","c1",54)
                };
    Heap<Item,comparer> heap(arr,4);
    heap.Add(Item("d","c1",51));
    heap.Add(Item("b","c1",54));
    heap.Add(Item("a","c1",40));
    heap.Add(Item("c","c1",11));
    std::cout << heap.Top() << std::endl;
    heap.Pop();
    heap.Pop();
    std::cout << heap.Top();
    return 0;
}
