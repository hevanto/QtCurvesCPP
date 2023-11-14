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
    float step = mIntervalLength / mStepCount;
    for (float t = 0; t < mIntervalLength; t += step) {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawPoint(pixel);
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
        break;
    case HuygensCycloid:
        break;
    case HypoCycloid:
        break;

    case FutureCurve:
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

    case FutureCurve:
        return computeFutureCurve(t);
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
    return QPointF();
}

QPointF RenderArea::computeHuygens(float t)
{
    return QPointF();
}

QPointF RenderArea::computeHypo(float t)
{
    return QPointF();
}

QPointF RenderArea::computeFutureCurve(float t)
{
    return QPointF();
}
