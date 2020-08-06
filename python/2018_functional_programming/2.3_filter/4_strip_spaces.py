#!/usr/bin/env python3

SENTENCE = 'Оно огорожено проволокой, а я бы выпил чаю.'

chars = list(filter(lambda ch: ch != ' ', SENTENCE))
print(''.join(chars))
