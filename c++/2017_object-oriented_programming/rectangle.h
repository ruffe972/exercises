#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QWidget *drawingArea, int x = 0, int y = 0, int width = 50, int height = 30);    
    float perimeter() const;
    float area() const;

private:
    void paintEvent(QPaintEvent *);
};

#endif // RECTANGLE_H
