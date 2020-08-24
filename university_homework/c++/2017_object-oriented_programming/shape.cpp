#include "shape.h"

Shape::Shape(QWidget *drawingArea, int x, int y) :
    QWidget(drawingArea),
    _fill(Qt::black, Qt::SolidPattern),
    _position(x, y)
{
    setVisible(false);
}

void Shape::initPainter(QPainter &painter) const
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(_fill);
}

const QBrush &Shape::getFill() const
{
    return _fill;
}

void Shape::setFill(const QBrush &fill)
{
    _fill = fill;
    update();
}

void Shape::draw()
{
    setVisible(true);
}

bool Shape::hitTest(int x, int y) const
{
    return x >= 0 && y >= 0 && x < size().width() && y < size().height();
}

const QPoint &Shape::getPosition() const
{
    return _position;
}

void Shape::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
    move(x, y);
}

bool Shape::compareByArea(const Shape *a, const Shape *b)
{
    return a->area() < b->area();
}
