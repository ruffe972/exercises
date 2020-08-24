#!/usr/bin/env python3

LIST_1 = [4, 5, 6, 7, 8]
LIST_2 = [2, 4, 6, 8, 10]
result = list(filter(lambda x: x in LIST_2, LIST_1))
print(result)
