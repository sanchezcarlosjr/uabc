import time


def search(arr, number):
    index = 0
    for i in arr:
        if number == i:
            return index
        index += 1
    return -1


def binarySearch(arr, number):
    lowerBound = 0
    upperBound = len(arr) - 1
    i=0
    while lowerBound <= upperBound:
        index = int((upperBound + lowerBound) / 2)
        if arr[index] <= number:
            lowerBound = index + 1
        if arr[index] >= number:
            upperBound = index - 1
        print(index)
    if arr[index] == number:
        return index
    return -1


def timeFunc(func):
    start = time.time()
    index = func([1, 2, 3, 4, 5, 6, 7, 8, 9], -1)
    end = time.time()
    print(f"Actual {index} Expected 0 {end - start}")


timeFunc(binarySearch)
