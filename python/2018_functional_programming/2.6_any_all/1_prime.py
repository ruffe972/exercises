#!/usr/bin/env python3

number = int(input('Введите натуральное число > 1: '))
candidates = list(range(2, number))
prime = not any(map(lambda x: number % x == 0, candidates))
print('Число простое.' if prime else 'Число составное.')
