#include "Banner.h"

Banner::Banner(QWidget *parent) {
    coinLabel = new QLabel("0", this);
    timerLabel = new QLabel("0", this);
    timer = new QTimer(this);
    button = new Button("PAUSE", this);
    player = new Player();

    connect(timer, &QTimer::timeout, this, &Banner::updateTimer);

    QWidget* containerWidget = new QWidget(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(containerWidget);

    coinLabel->setText("" + QString::number(player->getCoin()));

    mainLayout->addWidget(coinLabel);
    mainLayout->addWidget(timerLabel);
    mainLayout->addWidget(button);

    mainLayout->setAlignment(Qt::AlignTop);

    setLayout(mainLayout);

    timer->start(1000);
}

void Banner::updateTimer() {
    time++;
    int hours = time / 3600;
    int minutes = (time % 3600) / 60;
    int seconds = time % 60;
    QString timeSting = QString("%1:%2:%3").arg(hours,2,10,QChar('0')).arg(minutes,2,10,QChar('0')).arg(seconds,2,10,QChar('0'));
    timerLabel->setText("" + timeSting);
}