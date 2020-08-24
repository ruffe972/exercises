#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QPainter>

class Shape: public QWidget
{
    Q_OBJECT
public:
    const QPoint &getPosition() const;
    void setPosition(int x, int y);
    const QBrush &getFill() const;
    void setFill(const QBrush &fill);

    void draw();
    virtual bool hitTest(int x, int y) const;
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    static bool compareByArea(const Shape *a, const Shape *b);

protected:
    Shape(QWidget *drawingArea, int x, int y);
    void initPainter(QPainter &painter) const;

private:
    QBrush _fill;
    QPoint _position;
};

#endif // SHAPE_H
