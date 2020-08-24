#!/usr/bin/env python3
import random
import functools as fn

numbers = [random.randint(-49, 50) for i in range(10)]
count = fn.reduce(lambda x, y: x if y < 0 else x + 1, numbers, 0)
print('Исходная последовательность:', numbers)
print('Ответ:', [count] + numbers)
