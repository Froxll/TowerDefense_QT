#ifndef PROJETQT_TOWER_H
#define PROJETQT_TOWER_H

#include <QString>
#include <QDir>

class Tower {
    private:
        QString imagePath;
        int level;
        int damage;
        int range;
    public:
        Tower();
        int getLevel();
        int getDamage();
        int getRange();
        void addLevel();
        void addDamage(int x);
        QString getImagePath() const;
};

#endif //PROJETQT_TOWER_H
