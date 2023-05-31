//
// Created by Lilly on 28.05.2023.
//

#ifndef OPTOCUS_GRAPHICSPANEL_H
#define OPTOCUS_GRAPHICSPANEL_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QFileDialog>
#include <QInputDialog>

class GraphicsPanel : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    enum class DrawMode {
        Point,
        Line,
        Ray
    };

private:
    static const int WIDTH = 1200;
    static const int HEIGHT = 720;
    // TODO: replace with Lens (int future - list of Lenses)
    double lensPower = 0.0f;
    double focalLengthFront = 0.0f;
    double focalLengthBack = 0.0f;
    QPixmap pixmap;
    int cellSize;
    QVector<QPoint> points;
    QVector<QPair<QPoint, QPoint>> lines;
    QVector<QPair<QPoint, QPoint>> rays;
    QPoint startPoint;
    bool startPointSet = false;
    DrawMode drawMode = DrawMode::Point;

protected:
    float scaleFactor;

public:
    GraphicsPanel(QWidget* parent = nullptr) : QOpenGLWidget(parent) {
            setMouseTracking(true);
    }

    void setDrawMode(DrawMode mode) {
        drawMode = mode;
    }

    void clearPanel();
    void saveModel();
    void addLens();

protected:
    void initializeGL() override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    QPoint getCoordinates(double x, double y);
};

#endif //OPTOCUS_GRAPHICSPANEL_H