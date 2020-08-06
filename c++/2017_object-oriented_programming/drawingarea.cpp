#include "drawingarea.h"
#include "rectangle.h"
#include "circle.h"
#include <QMouseEvent>
#include <QTextStream>

DrawingArea::DrawingArea(QLabel *statusLabel) :
    QWidget(),
    _draggedShape(nullptr),
    _statusLabel(statusLabel)
{
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(palette);
    resetAndAddShapes();
}

DrawingArea::~DrawingArea()
{
}

void DrawingArea::randomFill() const
{
    for (Shape *shape: _shapes)
    {
        typedef enum Qt::GlobalColor colorT;
        QVector<colorT> colors = {Qt::black, Qt::darkGreen, Qt::blue, Qt::red};
        colorT color = colors[qrand() % colors.length()];

        typedef enum Qt::BrushStyle brushStyleT;
        QVector<brushStyleT> patterns = {Qt::SolidPattern, Qt::Dense1Pattern, Qt::Dense3Pattern};
        brushStyleT pattern = patterns[qrand() % patterns.length()];

        shape->setFill(QBrush(color, pattern));
    }
}

void DrawingArea::sortShapes() const
{
    auto sortedShapes = _shapes;
    std::sort(sortedShapes.begin(), sortedShapes.end(), Shape::compareByArea);
    arrangeShapes(sortedShapes);
}

void DrawingArea::arrangeShapes(const QVector<Shape *> &shapes)
{
    int x = 0;
    for (Shape *shape: shapes)
    {
        shape->setPosition(x, 0);
        x += shape->geometry().width();
    }
}

void DrawingArea::resetAndAddShapes() {
    qDeleteAll(_shapes);
    _shapes.clear();
    _shapes.append(new Rectangle(this, 400, 300, 50, 50));
    _shapes.append(new Circle(this, 200, 300, 25));
    _shapes.append(new Rectangle(this, 600, 300, 50, 50));
    _shapes.append(new Circle(this, 600, 100, 25));
    _shapes.append(new Rectangle(this));
    _shapes.append(new Circle(this));
    for (Shape *shape: _shapes)
    {
        shape->draw();
    }
    _shapes[0]->setFill(QBrush(Qt::blue, Qt::Dense1Pattern));
    _shapes[1]->setFill(QBrush(Qt::darkGreen, Qt::Dense3Pattern));
}

void DrawingArea::printDraggedShapeStatus() const
{
    QString string;
    QPoint pos = _draggedShape->getPosition();
    QTextStream(&string) << "x: " << pos.x() << ", y: " << pos.y()
                         << ", area: " << _draggedShape->area()
                         << ", perimeter: " << _draggedShape->perimeter();
    _statusLabel->setText(string);
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    Shape *shape = nullptr;
    auto it = _shapes.rbegin();
    bool found = false;
    while (it != _shapes.rend() && !found)
    {
        shape = *it;
        QPoint point = event->pos() - shape->pos();
        found = shape->hitTest(point.x(), point.y());
        it++;
    }
    if (found)
    {
        _lastClickPos = event->pos();
        _draggedShape = shape;
        printDraggedShapeStatus();
    }
}

void DrawingArea::mouseMoveEvent(QMouseEvent *event)
{
    if (_draggedShape)
    {
        QPoint pos = _draggedShape->pos() + event->pos() - _lastClickPos;
        _draggedShape->setPosition(pos.x(), pos.y());
        printDraggedShapeStatus();
        _lastClickPos = event->pos();
    }
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *)
{
    _draggedShape = nullptr;
}
