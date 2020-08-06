#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle(QWidget *drawingArea, int x = 0, int y = 0, int r = 10);
    float perimeter() const;
    float area() const;
    bool hitTest(int x, int y) const;

private:
    void paintEvent(QPaintEvent *);
    int _r;
};

#endif // CIRCLE_H
