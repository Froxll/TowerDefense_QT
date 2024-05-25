#include "Player.h"

Player::Player(){
    coin = 100;
    hp = 100;
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

int Player::getHP() {
    return hp;
}

void Player::addHP(int x) {
    hp = hp - x;
}

void Player::setCoin() {
    coin = 100;
}

void Player::setHP() {
    hp = 100;
}
