#ifndef PROJETQT_PLAYER_H
#define PROJETQT_PLAYER_H

class Player {
    private:
        int coin;
    public:
        Player();
        void addCoin(int x);
        void substractCoin(int x);
        int getCoin();
};

#endif //PROJETQT_PLAYER_H
