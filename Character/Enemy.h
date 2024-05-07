#ifndef PROJETQT_ENEMY_H
#define PROJETQT_ENEMY_H

class Enemy {
    private:
        int hp;
        int damage;
        int level;
    public:
        int getHP();
        int getDamage();
        void addLevel();
        void addDamage(int x);
        void addHP(int x);
};

#endif //PROJETQT_ENEMY_H
