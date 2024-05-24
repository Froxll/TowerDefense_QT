#include "Tower.h"

Tower::Tower(int level, int damage, int range, QPixmap towerItem){
    this->level = level;
    this->damage = damage;
    this->range = range;
    this->towerItem = towerItem;
    setPixmap(towerItem);
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

void Tower::addDamage(int x) {
    damage = damage + x;
}

void Tower::addLevel() {
    level++;
}

QPixmap Tower::getItem(){
    return towerItem;
}

int Tower::getTarget() {
    return target;
}

void Tower::setTarget(int i) {
    target = i;
}
