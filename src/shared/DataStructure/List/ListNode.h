//
// Created by cest on 13/03/21.
//

#ifndef UABC_LISTNODE_H
#define UABC_LISTNODE_H

template<class T>
class ListNode {
public:
    T element;
    ListNode *next;
    ListNode *previous;

    ListNode(T data) {
        this->element = data;
    }

    void setNext(ListNode<T> *next) {
        this->next = next;
        this->next->previous = this;
    }
};


#endif //UABC_LISTNODE_H
