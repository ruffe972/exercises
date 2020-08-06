#!/usr/bin/env python3


def is_prime(number):
    if number < 2:
        return False
    else:
        candidates = list(range(2, number))
        return not any(map(lambda x: number % x == 0, candidates))


number_strings = input('Введите целые неотрицательные числа через пробел: ').split(' ')
numbers = list(map(int, number_strings))
print(all(map(is_prime, numbers)))
