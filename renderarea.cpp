#include "renderarea.h"

#include <QPainter>

#include <iostream>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
    , mBackgroundColor(QColorConstants::Blue)
    , mShapeColor(QColorConstants::White)
    , mShape(Astroid)
{

}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

void RenderArea::setBackgroundColor(const QColor &color) {
    if (mBackgroundColor != color) {
        mBackgroundColor = color;
        this->repaint();
    }
}

void RenderArea::setShapeColor(const QColor &color) {
    if (mShapeColor != color) {
        mShapeColor = color;
        this->repaint();
    }
}

void RenderArea::setShape(const ShapeType &shape) {
    if (mShape != shape) {
        mShape = shape;
        this->repaint();
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (mShape) {
    case Astroid:
        mBackgroundColor = QColorConstants::Red;
        break;
    case Cycloid:
        mBackgroundColor = QColorConstants::Green;
        break;
    case HuygensCycloid:
        mBackgroundColor = QColorConstants::Blue;
        break;
    case HypoCycloid:
        mBackgroundColor = QColorConstants::Yellow;
        break;
    default:
        break;
    }

    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    // Drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    int stepCount = 256;
    float scale = 40;
    float intervalLength = M_PI * 2;
    float step = intervalLength / stepCount;
    for (float t = 0; t < intervalLength; t += step) {
        QPointF point = computeAsteroid(t);

        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());

        painter.drawPoint(pixel);
    }
}

QPointF RenderArea::computeAsteroid(float t)
{
    float cosT = cos(t);
    float sinT = sin(t);
    float x = 2 * cosT * cosT * cosT;
    float y = 2 * sinT * sinT * sinT;
    return QPointF(x, y);
}
