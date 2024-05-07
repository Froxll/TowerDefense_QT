#include "Menu.h"

Menu::Menu(QWidget* parent){
    setWindowTitle("Menu");
    setMinimumSize(800,600);

    QWidget* mainWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);

    button1 = new Button("Play",this);
    button2 = new Button("Parameter",this);
    button3 = new Button("Quit",this);
    parameter = new Parameter(this);
    game = new Game(this);

    connect(button2->getButton(), &QPushButton::clicked, this, [this](){
        showPara();
        closeWindow();
    });

    connect(button1->getButton(), &QPushButton::clicked, this, [this](){
        showGame();
        closeWindow();
    });

    connect(button3->getButton(), &QPushButton::clicked, this, &Menu::closeWindow);

    connect(parameter, &Parameter::openMenuClicked,this,[this](){
        show();
    });

    connect(game, &Game::openMenuClicked,this,[this](){
        show();
    });

    mainLayout->addWidget(button1);
    mainLayout->addWidget(button2);
    mainLayout->addWidget(button3);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}