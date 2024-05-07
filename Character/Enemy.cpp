#include "Enemy.h"

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
    hp = hp + x;
}