#ifndef PROJETQT_TOWER_H
#define PROJETQT_TOWER_H

class Tower {
    private:
        int level;
        int damage;
        int range;
    public:
        int getLevel();
        int getDamage();
        int getRange();
        void addLevel();
        void addDamage(int x);
};

#endif //PROJETQT_TOWER_H
