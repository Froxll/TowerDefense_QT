#ifndef PROJETQT_TOWER_H
#define PROJETQT_TOWER_H

#include <QString>
#include <QDir>
#include <QPoint>

class Tower {
    private:
        QPoint position;
        int level;
        int damage;
        int range;
    public:
        Tower();
        QPoint getPosition();
        int getLevel();
        int getDamage();
        int getRange();
        void addLevel();
        void addDamage(int x);
        void setPosition(QPoint &pos);

};

#endif //PROJETQT_TOWER_H
