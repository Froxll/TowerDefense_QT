#include "Enemy.h"

Enemy::Enemy(QPixmap Gob, float newHp, float newDmg, int newGold, int newLvl){
    this->img = Gob;
    this->hp = newHp;
    this->damage = newDmg;
    this->level = newLvl;
    this->gold = newGold;
    setPixmap(img);
}

Enemy::~Enemy(){

}

int Enemy::getHP() {
    return hp;
}

int Enemy::getDamage() {
    return damage;
}

void Enemy::addDamage(int x) {
    damage = damage + x;
}

void Enemy::addLevel() {
    level++;
}

void Enemy::addHP(int x) {
    hp = hp - x;
}

void Enemy::setDead() {
    dead = true;
}

bool Enemy::getDead() {
    return dead;
}
