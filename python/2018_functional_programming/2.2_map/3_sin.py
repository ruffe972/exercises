#!/usr/bin/env python3
from math import sin, pi

xValues = list(map(lambda x: x * pi / 6, range(-12, 13)))
yValues = list(map(lambda x: sin(2 * x) / 2, xValues))
print(yValues)
