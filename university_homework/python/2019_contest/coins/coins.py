#!/usr/bin/env python3

n = int(input())
values = list(map(int, input().split()))
values.sort(reverse=True)
for r in range(1, len(values) + 1):
    better_half = values[:r]
    if sum(better_half) > sum(values) / 2:
        print(len(better_half))
        break
