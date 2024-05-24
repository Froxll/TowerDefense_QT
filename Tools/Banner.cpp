#include "Banner.h"

Banner::Banner(QWidget *parent) {
    coinLabel = new QLabel("0", this);
    timerLabel = new QLabel("0", this);
    timer = new QTimer(this);
    button2 = new Button("JOUER",this);
    button = new Button("QUITTER", this);

    connect(timer, &QTimer::timeout, this, &Banner::updateTimer);
    connect(button2->getButton(), &QPushButton::clicked,[this]{
        startTimer();
    });

    QWidget* containerWidget = new QWidget(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(containerWidget);

    coinLabel->setText("Coins : ");

    mainLayout->addWidget(coinLabel);
    mainLayout->addWidget(timerLabel);
    mainLayout->addWidget(button2);
    mainLayout->addWidget(button);

    mainLayout->setAlignment(Qt::AlignTop);

    setLayout(mainLayout);
}

void Banner::updateTimer() {
    time++;
    int hours = time / 3600;
    int minutes = (time % 3600) / 60;
    int seconds = time % 60;
    QString timeSting = QString("%1:%2:%3").arg(hours,2,10,QChar('0')).arg(minutes,2,10,QChar('0')).arg(seconds,2,10,QChar('0'));
    timerLabel->setText("" + timeSting);
}

void Banner::startTimer() {
    timer->start(1000);
}
