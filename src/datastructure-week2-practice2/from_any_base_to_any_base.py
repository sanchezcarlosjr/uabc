import sys

from from_base_to_decimal import from_base_to_decimal
from from_decimal_to_base import from_decimal_to_base


def from_any_base_to_any_base(number, start_base, end_base):
    print(f"from base {start_base} to decimal")
    start_base_number = from_base_to_decimal(number, start_base)
    print(start_base_number, end="")
    print(f"\nfrom decimal to {end_base}")
    return from_decimal_to_base(start_base_number, end_base)


if __name__ == '__main__':
    start_base = int(sys.argv[2])
    number = int(sys.argv[1])
    print(from_any_base_to_any_base(number, int(sys.argv[2]), start_base))
