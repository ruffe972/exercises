#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QLabel>

class Shape;

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    DrawingArea(QLabel *statusLabel);
    ~DrawingArea();

public slots:
    void resetAndAddShapes();
    void randomFill() const;
    void sortShapes() const;

private:
    static void arrangeShapes(const QVector<Shape *> &shapes);
    void printDraggedShapeStatus() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);

    Shape *_draggedShape;
    QLabel *_statusLabel;
    QVector<Shape *> _shapes;
    QPoint _lastClickPos;
};

#endif // DRAWINGAREA_H
