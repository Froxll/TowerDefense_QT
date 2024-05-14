#include "MyView.h"

MyView::MyView(QWidget* parent) : QGraphicsView(parent) {
    this->setContentsMargins(0,0,0,0);
}

void MyView::resizeEvent(QResizeEvent* event) {
    this->fitInView(sceneRect());
}