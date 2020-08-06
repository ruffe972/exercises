#!/usr/bin/env python3
from math import cos

MESSAGE = 'Введите стороны и угол (в радианах) через пробел:\n'
side1, side2, corner = map(float, input(MESSAGE).split(' '))
print((lambda side1, side2, corner: side1 * side2 * cos(corner) / 2)(side1, side2, corner))
