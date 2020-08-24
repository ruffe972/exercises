#!/usr/bin/env python3

words = input('Введите слова через пробел: ').split(' ')
words_it = map(lambda word: word.lower(), words)
print(any(map(lambda word: word[0] == word[-1], words_it)))

