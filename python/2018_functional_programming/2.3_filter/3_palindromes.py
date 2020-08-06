#!/usr/bin/env python3

SENTENCE = 'Оно огорожено проволокой, а я бы выпил чаю.'

# Здесь я очень криво накодил, ну и ладно.
sentence = list(filter(lambda ch: ch.isalpha() or ch == ' ', SENTENCE.lower()))
words = ''.join(sentence).split(' ')

palindromes = list(filter(lambda word: word[0] == word[-1], words))
print('Предложение:', SENTENCE)
print('Палиндромы:', palindromes)
