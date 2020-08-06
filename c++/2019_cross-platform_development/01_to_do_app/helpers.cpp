#include "helpers.h"
#include <cmath>
#include <QApplication>
#include <QScreen>

static const int DEFAULT_DPI = 96;

int scaled(int value) {
    return trunc(value * qApp->primaryScreen()->logicalDotsPerInch() / DEFAULT_DPI);
}

QSize scaled(const QSize &size) {
    return QSize(scaled(size.width()), scaled(size.height()));
}
