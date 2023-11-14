#include "renderarea.h"

#include <QPainter>

#include <iostream>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
    , mBackgroundColor(QColorConstants::Blue)
    , mShapeColor(QColorConstants::White)
    , mShape(Astroid)
    , mScale(1)
    , mIntervalLength(0)
    , mStepCount(256)
{
    onShapeChanged();
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

void RenderArea::setBackgroundColor(const QColor &color)
{
    if (mBackgroundColor != color) {
        mBackgroundColor = color;
        this->repaint();
    }
}

void RenderArea::setShapeColor(const QColor &color)
{
    if (mShapeColor != color) {
        mShapeColor = color;
        this->repaint();
    }
}

void RenderArea::setShape(const ShapeType &shape)
{
    if (mShape != shape) {
        mShape = shape;
        onShapeChanged();
        this->repaint();
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);


    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    // Drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());
    float step = mIntervalLength / mStepCount;
    for (float t = step; t < mIntervalLength; t += step) {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawPoint(pixel);
        painter.drawLine(pixel, prevPixel);
        prevPixel = pixel;
    }
}

void RenderArea::onShapeChanged()
{
    switch (mShape) {
    case Astroid:
        mScale = 40;
        mIntervalLength = M_PI * 2;
        mStepCount = 256;
        break;
    case Cycloid:
        mScale = 4;
        mIntervalLength = M_PI * 6;
        mStepCount = 128;
        break;
    case HuygensCycloid:
        mScale = 4;
        mIntervalLength = M_PI * 4;
        mStepCount = 256;
        break;
    case HypoCycloid:
        mScale = 15;
        mIntervalLength = M_PI * 2;
        mStepCount = 256;
        break;
    case Line:
        mScale = 100;
        mIntervalLength = 1;
        mStepCount = 128;
        break;
    default:
        break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (mShape) {
    case Astroid:
        return computeAstroid(t);
    case Cycloid:
        return computeCycloid(t);
    case HuygensCycloid:
        return computeHuygens(t);
    case HypoCycloid:
        return computeHypo(t);
    case Line:
        return computeLine(t);
    default:
        return QPointF();
    }
}

QPointF RenderArea::computeAstroid(float t)
{
    float cosT = cos(t);
    float sinT = sin(t);
    float x = 2 * cosT * cosT * cosT;
    float y = 2 * sinT * sinT * sinT;
    return QPointF(x, y);
}

QPointF RenderArea::computeCycloid(float t)
{
    return QPointF(
        1.5 * (1 - cos(t)),
        1.5 * (t - sin(t))
    );
}

QPointF RenderArea::computeHuygens(float t)
{
    return QPointF(
        4 * (3 * cos(t) - cos(3 * t)),
        4 * (3 * sin(t) - sin(3 * t))
    );
}

QPointF RenderArea::computeHypo(float t)
{
    return QPointF(
        1.5 * (2 * cos(t) + cos(2 * t)),
        1.5 * (2 * sin(t) - sin(2 * t))
    );
}

QPointF RenderArea::computeLine(float t)
{
    return QPointF(
        1-t,
        1-t
    );
}
