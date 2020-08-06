#!/usr/bin/env python3

MESSAGE = 'Введите предложение:\n'
words = input(MESSAGE).split(' ')
print((lambda words: words[-1])(words))
