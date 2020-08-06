#!/usr/bin/env python3

start_x, start_y = map(int, input().split())
target_x, target_y = map(int, input().split())
turns = 0
if target_y == start_y:
    turns = 0 if target_x <= start_x else 3
else:
    turns = 1 if target_x < start_x else 2
print(turns)
