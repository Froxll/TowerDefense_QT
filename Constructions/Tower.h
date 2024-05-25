#ifndef PROJETQT_TOWER_H
#define PROJETQT_TOWER_H

#include <QString>
#include <QDir>
#include <QPoint>
#include <QObject>
#include <QGraphicsPixmapItem>

class Tower :  public QGraphicsPixmapItem, public QObject{
    private:
        QGraphicsEllipseItem* rangeItem;
        QPixmap towerItem;
        int target = 0;
        int level;
        int damage;
        int range;
    public:
        Tower(int level = 1, int damage = 180, int range = 150, QPixmap towerItem = QPixmap(QDir::currentPath()+"/../Image/tour.png"));
        QPixmap getItem();
        int getTarget();
        int getLevel();
        int getDamage();
        int getRange();
        void setTarget(int i);
        void addLevel();
        void addDamage(int x);
        void setRangeItem(QGraphicsEllipseItem* rangeItem){
            this->rangeItem = rangeItem;
        }
        QGraphicsEllipseItem* getRangeItem(){
            return rangeItem;
        }
};

#endif //PROJETQT_TOWER_H
