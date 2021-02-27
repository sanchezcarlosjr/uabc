//
// Created by cest on 26/02/21.
//

#ifndef UABC_QUEUE_NODE_H
#define UABC_QUEUE_NODE_H

template<class T>
class QueueNode {
private:
    T data;
    QueueNode* next;
    QueueNode* previous;
public:
    QueueNode(T data, QueueNode* next) {
        this->data = data;
        this->next = next;
        if (this->next != 0) {
            this->next->previous = this;
        }
    }
    T moveToPrevious() {
        T element = this->data;
        QueueNode* previous = this->previous;
        this->next = previous->next;
        this->data = previous->data;
        if (previous->previous != 0) {
            this->previous = previous->previous;
            delete previous;
        }
        return element;
    }
};

#endif //UABC_QUEUE_NODE_H
