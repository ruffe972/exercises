#include "rectangle.h"

Rectangle::Rectangle(QWidget *drawingArea, int x, int y, int width, int height) :
    Shape(drawingArea, x, y)
{
    setGeometry(x, y, width, height);
}

float Rectangle::area() const
{
    return size().width() * size().height();
}

float Rectangle::perimeter() const
{
    return 2 * (size().width() + size().height());
}

void Rectangle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    initPainter(painter);
    painter.drawRect(0, 0, size().width(), size().height());
}
