#!/usr/bin/env python3

n = int(input('Введите n: '))
order = list(range(n))
get_fibonacci = lambda i: i if i < 2 else get_fibonacci(i - 1) + get_fibonacci(i - 2)
numbers = list(map(get_fibonacci, order))
tuples = zip(numbers, order)
print(numbers)
