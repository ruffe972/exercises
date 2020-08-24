#!/usr/bin/env python3
import random
import functools as fn

random_list = [random.randint(0, 10) for i in range(6)]
print('Исходная последовательность:', random_list)
answer = fn.reduce(lambda x, y: x + y, random_list, 0)
print('Ответ:', answer)
