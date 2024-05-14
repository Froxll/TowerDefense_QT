#include "Tower.h"

Tower::Tower(){
    level = 1;
    damage = 60;
    range = 30;
    imagePath = QDir::currentPath()+"/../Image/tour.png";
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

QString Tower::getImagePath() const {
    return imagePath;
}