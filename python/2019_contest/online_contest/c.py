import math


def chunks(list_arg, n):
    for i in range(0, len(list_arg), n):
        yield list_arg[i:i + n]


base_p, base_q = map(int, input().split())
num_p = input()
m = math.log(base_q, base_p)
if not m.is_integer() or m < 2:
    print('no')
else:
    m = int(m)
    rem = len(num_p) % m
    if rem != 0:
        num_p = '0' * (m - rem) + num_p
    groups = chunks(num_p, m)

    print('yes')
    for p_group in groups:
        acc = 0
        cur_base = 1
        for digit in p_group[::-1]:
            acc += int(digit) * cur_base
            cur_base *= base_p
        print(p_group, acc)
