#include "Tower.h"

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

void Tower::addLevel(int x) {
    level = level + x;
}