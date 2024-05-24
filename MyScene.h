#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QApplication>
#include <deque>
#include <vector>
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
//include Enemy
#include "Character/Enemy.h"

using namespace std;

class MyScene : public QGraphicsScene {
    Q_OBJECT
    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void addTower(QPoint position);
        void drawBackground(QPainter* painter, const QRectF &rect) override;
        void addGobelinGauche();
        void addGobelinHaut();
        void addGobelinBas();
    private:
        QTimer* timer;
        QPixmap mapBackground;
        QString imagePath;
        QPixmap background;
        deque<function<void()>> enemy_queue;
        void addEnemies(int waveNumber,int nb_ennemy);
        void processEnemyQueue(int waveNumber);
        std::vector<Tower*> list_of_tower;
        vector<Enemy*> list_of_enemy;
    public:
        MyScene(const QSize& size, QObject* parent = nullptr);
        virtual ~MyScene();
        void launchWave(int waveNumber);
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
