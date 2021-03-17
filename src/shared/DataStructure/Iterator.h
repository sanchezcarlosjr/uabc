//
// Created by cest on 13/03/21.
//

#ifndef UABC_ITERATOR_H
#define UABC_ITERATOR_H

template<class T>
class Iterator {
public:
    virtual void first() = 0;

    virtual bool isDone() = 0;

    virtual T current() = 0;

    virtual void next() = 0;
};


#endif //UABC_ITERATOR_H
