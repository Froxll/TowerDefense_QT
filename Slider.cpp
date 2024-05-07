#include "Slider.h"

Slider::Slider(QWidget* parent) {
    //initialisation of the slider
    slider = new QSlider(Qt::Horizontal,this);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(0);
    //Creation of the layout
    QHBoxLayout* horizontalayout = new QHBoxLayout(this);
    horizontalayout->addWidget(slider);
    setLayout(horizontalayout);
}