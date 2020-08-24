#!/usr/bin/env python3

MATRIX_1 = [[1, 2, 3],
            [3, 2, 1],
            [1, 2, 3]]
MATRIX_2 = [[-1, -2, -3],
            [0, 0, 0],
            [10, 10, -10]]


def lists_sum(list_1, list_2):
   return list(map(lambda x, y: x + y, list_1, list_2))


matrices_sum = list(map(lists_sum, MATRIX_1, MATRIX_2))
print(matrices_sum)
