import sys
from math import trunc


def from_decimal_to_base(number, base):
    base_number = ""
    q = number
    while q > 0:
        qk = trunc(q / base)
        ak = q - base * qk
        temp = str(trunc(ak))
        if base == 16:
            temp = hex(trunc(ak))
        base_number = temp + base_number
        print(f'{base * qk + ak}={base}*{qk}+{temp}')
        q = qk
    return base_number


if __name__ == '__main__':
    print(from_decimal_to_base(int(sys.argv[1]), int(sys.argv[2])))
