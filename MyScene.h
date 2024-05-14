#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QApplication>
//include Map
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDir>
#include <QDebug>
#include <QPainter>
//include Timer
#include <QTimer>
//include Tower
#include "Constructions/Tower.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class MyScene : public QGraphicsScene {
    Q_OBJECT
    protected:
        void drawBackground(QPainter* painter, const QRectF &rect) override;
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void addTower(const QPoint& position);
    private slots:
        void update();
    private:
        QTimer* timer;
        QPixmap mapBackground;
    public:
        MyScene(QObject* parent = nullptr);
        virtual ~MyScene();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
