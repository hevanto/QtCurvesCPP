#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QColor>
#include <QWidget>

class RenderArea : public QWidget
{
public:
    enum ShapeType {
        Astroid,
        Cycloid,
        HuygensCycloid,
        HypoCycloid,
        FutureCurve
    };


    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

signals:


    // QWidget interface
public:
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void setBackgroundColor(const QColor &color);
    inline QColor backgroundColor() const noexcept { return mBackgroundColor; }

    void setShapeColor(const QColor &color);
    inline QColor shapeColor() const noexcept { return mShapeColor; }

    void setShape(const ShapeType &shape);
    inline ShapeType Shape() const noexcept { return mShape; }

protected:
    void paintEvent(QPaintEvent *event);

private:
    void onShapeChanged();

    QPointF compute(float t);
    QPointF computeAstroid(float t);
    QPointF computeCycloid(float t);
    QPointF computeHuygens(float t);
    QPointF computeHypo(float t);
    QPointF computeFutureCurve(float t);

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;

};

#endif // RENDERAREA_H
