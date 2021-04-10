/*
        Shared
        Created by Carlos Sanchez
        Created at 26/02/21
*/

#include "Math/Random.h"
#include <iostream>
#include "System/Timer.h"

#include <chrono>
using namespace std::chrono;

using namespace std;

void insertSort(int a[], int length) {
    int i, j, value;
    for (i = 0; i < length; i++) {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
}

class Array {
private:
    int *array;
private:
    int iterator;
private:
    int size;

public:
    Array() {
        this->array = NULL;
        this->iterator = 0;
        this->size = 10;
        array = resize();
    }

public:
    void push(int value) {
        array[iterator] = value;
        iterator++;
        size++;
        array = resize();
    }

public:
    int getSize() {
        int overFlow = 10;
        return this->size - overFlow;
    }

private:
    int *resize() {
        int newSize = size * sizeof(int);
        return (int *) realloc(array, newSize);
    }

public:
    int operator[](int value) {
        return array[value];
    }

public:
    void replaceRepeated() {
        int temp = (int) NULL;
        for (int i = 0; i < getSize(); i++) {
            if (temp == array[i]) {
                array[i] = -5;
            } else {
                temp = array[i];
            }
        }
    }

public:
    void sort() {
        int startIndex = 0;
        int endIndex = getSize()-1;
        int topOfStack = -1;
        int auxiliarStack[endIndex - startIndex + 1];
        auxiliarStack[++topOfStack] = startIndex;
        auxiliarStack[++topOfStack] = endIndex;
        while (topOfStack >= 0) {
            endIndex = auxiliarStack[topOfStack--];
            startIndex = auxiliarStack[topOfStack--];
            int positionPivot = partition(startIndex, endIndex);
            //Apilar al lado izquierdo
            if (positionPivot - 1 > startIndex) {
                auxiliarStack[++topOfStack] = startIndex;
                auxiliarStack[++topOfStack] = positionPivot - 1;
            }
            //Apilar al lado derecho
            if (positionPivot + 1 < endIndex) {
                auxiliarStack[++topOfStack] = positionPivot + 1;
                auxiliarStack[++topOfStack] = endIndex;
            }
        }
    }


public:
    int partition(int startIndex, int endIndex) {
        int mainElement = this->array[endIndex];
        int pivot = startIndex - 1;

        for (int i = startIndex; i <= endIndex - 1; i++) {
            if (this->array[i] <= mainElement) {
                pivot++;
                swap(pivot, i);
            }
        }

        swap(pivot + 1, endIndex);

        return (pivot + 1);
    }

public:
    void swap(int initialPosition, int finalPosition) {
        int temp = array[initialPosition];
        array[initialPosition] = array[finalPosition];
        array[finalPosition] = temp;
    }


};


int main() {
    Array* array = new Array();
    for (int i = 0; i < 100000; i++) {
        array->push(Random::Number());
    }
    time([array]() {
        array->sort();
    });
    return 0;
}
