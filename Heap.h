//
// Created by AhmedOsama on 5/11/2024.
//

#ifndef DATASTRUCTURES_A2_HEAP_H
#define DATASTRUCTURES_A2_HEAP_H

#include <utility>
#include <stdexcept>

template<typename T, typename Cmp = std::greater<>>
class Heap {
    T *heap;
    Cmp compare;
    const int INITIAL_CAPACITY = 1;
    int cur_size = 0;
    int capacity = INITIAL_CAPACITY;
    void heapifyUp(int pos);
    void heapifyDown(int pos);
    int parent(int pos) {return pos >> 1;}
    int left(int pos) {return (pos << 1) > cur_size ? -1 : (pos << 1);}
    int right(int pos){return (pos << 1) + 1 > cur_size ? -1 : (pos << 1) + 1;}
public:
    int Size() {return cur_size;}
    Heap() { heap = new T[INITIAL_CAPACITY]; }
    Heap(T* arr,int n) {
        cur_size = n;
        capacity = n << 1;
        heap = new T[capacity];
        for (int i = 0; i < n; ++i) heap[i + 1] = arr[i];
        for (int i = n; i; --i) heapifyDown(i);
    }
    void Add(T item) {
        if(capacity <= cur_size + 1) {
            T* cur = new T[capacity << 1];
            for (int i = 0; i < capacity; ++i) cur[i] = heap[i];
            std::swap(cur,heap);
            capacity <<= 1;
            delete[] cur;
        }
        ++cur_size;
        heap[cur_size] = item;
        heapifyUp(cur_size);
    }
    T Top() {
        if(cur_size == 0) throw std::out_of_range("out of range!");
        return heap[1];
    }
    void Pop() {
        if(cur_size == 0) throw std::out_of_range("out of range!");
        std::swap(heap[1],heap[cur_size]);
        --cur_size;
        heapifyDown(1);
    }
};

template<typename T, typename Cmp>
void Heap<T,Cmp>::heapifyUp(int pos) {
    if(!parent(pos) || !compare(heap[pos],heap[parent(pos)])) return;
    std::swap(heap[pos],heap[parent(pos)]);
    heapifyUp(parent(pos));
}

template<typename T, typename Cmp>
void Heap<T, Cmp>::heapifyDown(int pos) {
    int smallest = left(pos);
    if(smallest == -1) return;
    if(right(pos) != -1 && compare(heap[right(pos)],heap[smallest])) {
        smallest = right(pos);
    }
    if(!compare(heap[smallest],heap[pos])) return;
    std::swap(heap[smallest], heap[pos]);
    heapifyDown(smallest);
}






#endif //DATASTRUCTURES_A2_HEAP_H
