#!/usr/bin/env python3
import random
import functools as fn

random_list = [random.randint(0, 6) for i in range(6)]
print('Исходная последовательность:', random_list)
even_numbers_filter = filter(lambda x: x % 2 == 0, random_list)
answer = fn.reduce(lambda x, y: x + y * y, even_numbers_filter, 0)
print('Ответ:', answer)
