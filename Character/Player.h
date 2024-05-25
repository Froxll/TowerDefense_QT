#ifndef PROJETQT_PLAYER_H
#define PROJETQT_PLAYER_H

class Player {
    private:
        int hp;
        int coin;
    public:
        Player();
        void addCoin(int x);
        void substractCoin(int x);
        int getCoin();
        void addHP(int x);
        int getHP();
        void setCoin();
        void setHP();
};

#endif //PROJETQT_PLAYER_H
