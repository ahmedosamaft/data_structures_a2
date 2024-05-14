//
// Created by AhmedOsama on 5/8/2024.
//

#ifndef DATASTRUCTURES_A2_BINARYSEARCHTREE_H
#define DATASTRUCTURES_A2_BINARYSEARCHTREE_H

#include <utility>
#include <iostream>


template<typename T, typename Cmp>
class BinarySearchTree {
    class Node {
    public:
        T value;
        Node *left = nullptr;
        Node *right = nullptr;

        explicit Node(T value) : value(value) {}
    };

    Node *root = nullptr;
    Cmp compare;

    void Add(T &element, Node **cur);

    bool Delete(T &element, Node **cur);

    void ShowAscending(Node *cur);

    void ShowDescending(Node *cur);

public:
    void Add(T element);

    bool Delete(T element); /* true if deleted successfully */

    void ShowAscending(); /* Like in order  */

    void ShowDescending(); /* Like in order  */

};

template<typename T, typename Cmp>
void BinarySearchTree<T, Cmp>::ShowDescending(BinarySearchTree::Node *cur) {
    if (cur == nullptr) return;
    ShowDescending(cur->right);
    std::cout << cur->value << " ";
    ShowDescending(cur->left);

}

template<typename T, typename Cmp>
void BinarySearchTree<T, Cmp>::ShowDescending() {
    ShowDescending(root);
}

template<typename T, typename Cmp>
void BinarySearchTree<T, Cmp>::ShowAscending() {
    ShowAscending(root);
}

template<typename T, typename Cmp>
void BinarySearchTree<T, Cmp>::ShowAscending(BinarySearchTree::Node *cur) {
    if (cur == nullptr) return;
    ShowAscending(cur->left);
    std::cout << cur->value << " ";
    ShowAscending(cur->right);
}

template<typename T, typename Cmp>
bool BinarySearchTree<T, Cmp>::Delete(T &element, Node **cur) {
    if (*cur == nullptr) return false; /* not found */
    if ((*cur)->value == element) {
        if ((*cur)->left == nullptr && (*cur)->right == nullptr) /* leaf */ {
            delete *cur;
            *cur = nullptr;
            return true;
        }
        if ((*cur)->left != nullptr) /* go to left */ {
            std::swap((*cur)->left->value, (*cur)->value);
            return Delete(element, &(*cur)->left);
        }
        if ((*cur)->right != nullptr) /* go to right */  {
            std::swap((*cur)->right->value, (*cur)->value);
            return Delete(element, &(*cur)->right);
        }
    }
    if (compare((*cur)->value, element)) return Delete(element, &(*cur)->right);
    return Delete(element, &(*cur)->left);
}

template<typename T, typename Cmp>
void BinarySearchTree<T, Cmp>::Add(T &element, Node **cur) {
    if (*cur == nullptr) {
        *cur = new Node(element);
        return;
    }
    if (compare((*cur)->value, element)) Add(element, &(*cur)->right);  /* go to right */
    else Add(element, &(*cur)->left);  /* go to left */
}

template<typename T, typename Cmp>
bool BinarySearchTree<T, Cmp>::Delete(T element) {
    return Delete(element, &root);
}

template<typename T, typename Cmp>
void BinarySearchTree<T, Cmp>::Add(T element) {
    Add(element, &root);
}


#endif //DATASTRUCTURES_A2_BINARYSEARCHTREE_H
