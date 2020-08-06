import tkinter as tk
from math import cos, sin
import math
import random

WINDOW_WIDTH = 400
WINDOW_HEIGHT = 300
RADIUS = 15
# collision detection works only for not very high SPEED in comparison to the RADIUS
SPEED = 10
FRAME_DELAY = 30
DESIRED_AMOUNT = 6  # should be > 0
INITIAL_OFFSET = RADIUS * 2 + 10


class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y


class Molecule:
    # window
    w = None
    color_index = 0
    molecules = []

    def __init__(self, pos, angle, color):
        self.v = Point(cos(angle) * SPEED, sin(angle) * SPEED)
        x2, y2 = get_x2_and_y2(pos.x, pos.y)
        self.id = self.w.create_oval(pos.x, pos.y, x2, y2, fill=color, outline=color)

    def move(self):
        x1, y1, _, _ = self.w.coords(self.id)
        x1 += self.v.x
        y1 += self.v.y
        x2, y2 = get_x2_and_y2(x1, y1)
        other = overlapping_molecule(self, x1, y1)
        if other:
            self.v.x *= -1
            self.v.y *= -1
        else:
            if x1 < 0:
                self.v.x *= -1
                x1 = -x1
            elif x2 >= WINDOW_WIDTH:
                self.v.x *= -1
                x1 -= x2 - WINDOW_WIDTH + 1
            if y1 < 0:
                self.v.y *= -1
                y1 = -y1
            elif y2 >= WINDOW_HEIGHT:
                self.v.y *= -1
                y1 -= y2 - WINDOW_HEIGHT + 1
            x2, y2 = get_x2_and_y2(x1, y1)
            self.w.coords(self.id, x1, y1, x2, y2)


def overlapping_molecule(molecule_a, x1, y1) -> Molecule:
    for molecule in Molecule.molecules:
        if molecule_a != molecule and overlaps(molecule, get_center(x1, y1)):
            return molecule
    return None


def overlaps(molecule_b, center):
    x1_b, y1_b, _, _ = Molecule.w.coords(molecule_b.id)
    center_b = get_center(x1_b, y1_b)
    return math.hypot(center.x - center_b.x, center.y - center_b.y) <= 2 * RADIUS


def get_center(x1, y1):
    return Point(x1 + RADIUS, y1 + RADIUS)


def get_x2_and_y2(x1, y1):
    return x1 + RADIUS * 2 - 1, y1 + RADIUS * 2 - 1


def animate():
    for molecule in Molecule.molecules:
        molecule.move()
    Molecule.w.after(FRAME_DELAY, animate)


def arranged_molecules():
    molecules = []
    i, x1, y1 = 0, 0, 0
    finished = False
    while not finished:
        angle = random.uniform(0, 2 * math.pi)
        color = 'blue' if i == 0 else 'red'
        molecules.append(Molecule(Point(x1, y1), angle, color))
        i += 1
        x1 += INITIAL_OFFSET
        x2, _ = get_x2_and_y2(x1, y1)
        if x2 >= WINDOW_WIDTH:
            x1 = 0
            y1 += INITIAL_OFFSET
        _, y2 = get_x2_and_y2(x1, y1)
        finished = i >= DESIRED_AMOUNT or y2 >= WINDOW_HEIGHT
    return molecules


def key_press(event):
    molecule = Molecule.molecules[0]
    if event.keysym == 'Left':
        molecule.v = Point(-SPEED, 0)
    elif event.keysym == 'Right':
        molecule.v = Point(SPEED, 0)
    elif event.keysym == 'Up':
        molecule.v = Point(0, -SPEED)
    elif event.keysym == 'Down':
        molecule.v = Point(0, SPEED)


def main():
    w = tk.Canvas(tk.Tk(), width=WINDOW_WIDTH, height=WINDOW_HEIGHT, highlightthickness=0)
    Molecule.w = w
    w.focus_set()
    w.bind("<Key>", key_press)
    w.pack()
    Molecule.molecules = arranged_molecules()
    animate()
    tk.mainloop()


if __name__ == '__main__':
    main()
