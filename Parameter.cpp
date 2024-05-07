#include "Parameter.h"

Parameter::Parameter(QWidget* parent){
    setWindowTitle("Parameter");
    setMinimumSize(800,600);

    QWidget* mainWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(mainWidget);

    button = new Button("Return",this);
    slider = new Slider(this);

    mainLayout->addWidget(slider);
    mainLayout->addWidget(button);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    connect(button->getButton(), &QPushButton::clicked, this, [this](){
        close();
        emit openMenu();
    });
}

void Parameter::openMenu() {
    emit openMenuClicked();
}
