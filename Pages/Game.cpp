#include "Game.h"

Game::Game(QWidget *parent) {
    setWindowTitle("Game");
    setMinimumSize(800,600);

    QWidget* mainWidget = new QWidget(this);
    QVBoxLayout* bannerLayout = new QVBoxLayout(mainWidget);

    QPixmap imMap("map.jpeg");

    banner = new Banner(this);
    banner->setFixedSize(800,200);

    bannerLayout->addWidget(banner);

    mainWidget->setLayout(bannerLayout);
    setCentralWidget(mainWidget);
}

void Game::openMenu() {
    emit openMenuClicked();
}