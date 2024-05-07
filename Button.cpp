#include "Button.h"

Button::Button(const QString& buttonText, QWidget* parent){
    button = new QPushButton(buttonText ,this);
    button->setFixedSize(100,40);
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(button);
    setLayout(mainLayout);
}
