import math
import sys


def a(number, k):
    return math.trunc(number / math.pow(10, k)) % 10


def length(number):
    return math.trunc(math.log10(number)) + 1


def from_base_to_decimal(number, b):
    acc = 0
    for k in range(length(number)):
        print(f'+{a(number, k)}*2^{k}', end=' ')
        acc += a(number, k) * math.pow(b, k)
    print("=", end="")
    return acc


print(from_base_to_decimal(int(sys.argv[1]), int(sys.argv[2])))
