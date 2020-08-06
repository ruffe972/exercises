#!/usr/bin/env python3
import functools as fn

n = int(input('Введите N: '))
result = fn.reduce(lambda x, y: x * y, range(1, n + 1), 1)
print(result)
