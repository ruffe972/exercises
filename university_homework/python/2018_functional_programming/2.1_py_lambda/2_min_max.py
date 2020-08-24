#!/usr/bin/env python3

MESSAGE = 'Введите вещественные числа через пробел\n'
numbers = list(map(float, input(MESSAGE).split(' ')))
print((lambda numbers: (min(numbers) + max(numbers)) / 2)(numbers))
