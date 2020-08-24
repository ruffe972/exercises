#!/usr/bin/env python3
import random
import functools as fn

numbers = [random.randint(-49, 50) for i in range(10)]
max_number = fn.reduce(lambda x, y: x if x > y else y, numbers, numbers[0])
print('Исходная последовательность:', numbers)
print('Ответ:', max_number)
