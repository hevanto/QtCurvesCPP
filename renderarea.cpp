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
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
