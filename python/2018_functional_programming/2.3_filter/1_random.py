#!/usr/bin/env python3
import random

random_list = [random.randint(0, 30) for i in range(20)]
print('Исходная последовательность:', random_list)
filtered_list = list(filter(lambda x: x % 3 != 0, random_list))
print('Ответ:', filtered_list)
