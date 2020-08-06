#!/usr/bin/env python3

number_strings = input('Введите числа через пробел: ').split(' ')
numbers = list(map(int, number_strings))
print(all(map(lambda x: x % 2 == 0, numbers)))
