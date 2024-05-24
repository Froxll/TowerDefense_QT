#include "Tower.h"

Tower::Tower(){
    level = 1;
    damage = 60;
    range = 150;
}

int Tower::getLevel() {
    return level;
}

int Tower::getDamage() {
    return damage;
}

int Tower::getRange() {
    return range;
}

QPoint Tower::getPosition() {
    return position;
}

void Tower::addDamage(int x) {
    damage = damage + x;
}

void Tower::addLevel() {
    level++;
}

void Tower::setPosition(QPoint &pos) {
    position = pos;
}