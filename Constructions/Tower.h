#ifndef PROJETQT_TOWER_H
#define PROJETQT_TOWER_H

#include <QString>
#include <QDir>
#include <QPoint>
#include <QObject>
#include <QGraphicsPixmapItem>

class Tower :  public QGraphicsPixmapItem, public QObject{
    private:
        QPixmap towerItem;
        int level;
        int damage;
        int range;
    public:
        Tower(int level = 1, int damage = 60, int range = 150, QPixmap towerItem = QPixmap(QDir::currentPath()+"/../Image/tour.png"));
        QPixmap getItem();
        int getLevel();
        int getDamage();
        int getRange();
        void addLevel();
        void addDamage(int x);

};

#endif //PROJETQT_TOWER_H
