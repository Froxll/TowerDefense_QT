#ifndef PROJETQT_ENEMY_H
#define PROJETQT_ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDir>

class Enemy : public QObject, public QGraphicsPixmapItem{
    private:
        QPixmap img;
        float hp;
        float damage;
        int level;
        int gold;
    public:
        Enemy(QPixmap Gob = QPixmap(QDir::currentPath() + "/../Image/marche_bas_1_enorme.png"), float newHp = 100, float newDmg = 10, int newGold = 5, int newLvl = 1);
        ~Enemy();
        int getHP();
        int getDamage();
        void addLevel();
        void addDamage(int x);
        void addHP(int x);
        QGraphicsItem getImg();
};

#endif //PROJETQT_ENEMY_H
