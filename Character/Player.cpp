#include "Player.h"

Player::Player(){
    coin = 100;
}

void Player::addCoin(int x) {
    coin = coin + x;
}

void Player::substractCoin(int x) {
    coin = coin - x;
}

int Player::getCoin(){
    return coin;
}
