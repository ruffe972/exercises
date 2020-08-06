#!/usr/bin/env python3

SENTENCE = 'Оно огорожено проволокой, а я бы выпил чаю.'

sentence = list(filter(lambda ch: ch.isalpha(), SENTENCE))
print(''.join(sentence))
