import sys
from math import trunc


def from_decimal_to_base(number, base):
    base_number = ""
    q = number
    while q > 0:
        qk = trunc(q/base)
        ak = q - base*qk
        base_number = str(ak)+base_number
        print(f'{base*qk+ak}={base}*{qk}+{ak}')
        q = qk
    return base_number


print(from_decimal_to_base(int(sys.argv[1]), int(sys.argv[2])))
