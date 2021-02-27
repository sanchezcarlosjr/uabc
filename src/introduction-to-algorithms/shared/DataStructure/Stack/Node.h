//
// Created by cest on 20/02/21.
//
#ifndef UABC_NODE_H
#define UABC_NODE_H

template <class T>
class Node {
public:
    T element;
    Node<T>* next = nullptr;
    Node(T element, Node<T>* next) {
        this->element = element;
        this->next = next;
    }
    static T moveToNext(Node*& top) {
        T element = top->element;
        Node* formerTop = top;
        if (top->next != 0) {
            top = top->next;
        }
        delete formerTop;
        return element;
    }
};

#endif //UABC_NODE_H
