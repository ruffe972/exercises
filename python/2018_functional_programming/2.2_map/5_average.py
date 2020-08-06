#!/usr/bin/env python3

LIST_1 = [3, 4, 5]
LIST_2 = [6, 7, 8]
LIST_3 = [3, 4, 8]

result = list(map(lambda *args: sum(args) / len(args), LIST_1, LIST_2, LIST_3))
print(result)
