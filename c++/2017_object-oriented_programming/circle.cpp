#include "circle.h"
#include <cmath>

Circle::Circle(QWidget *drawingArea, int x, int y, int r) :
    Shape(drawingArea, x, y),
    _r(r)
{
    setGeometry(x, y, 2 * r, 2 * r);
}

float Circle::area() const
{
    return M_PI * _r * _r;
}

float Circle::perimeter() const
{
    return 2 * M_PI * _r;
}

void Circle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    initPainter(painter);
    painter.drawEllipse(0, 0, 2 * _r, 2 * _r);
}

bool Circle::hitTest(int x, int y) const
{
    return pow((x - _r), 2) + pow((y - _r), 2) < pow(_r, 2);
}
