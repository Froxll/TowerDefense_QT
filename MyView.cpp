#include "MyView.h"

MyView::MyView(QWidget* parent) : QGraphicsView(parent) {
    setFixedSize(900,600);
}

void MyView::resizeEvent(QResizeEvent* event) {
    QGraphicsView::resizeEvent(event);
    setFixedSize(this->size());
}