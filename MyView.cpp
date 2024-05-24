#include "MyView.h"

MyView::MyView(QWidget* parent) : QGraphicsView(parent) {
    this->setContentsMargins(0,0,0,0);
}

void MyView::resizeEvent(QResizeEvent* event) {
    //this->fitInView(sceneRect());
}

void MyView::zoomOut() {
    double newZoom = zoomFactor / 1.2;
    if(newZoom >= 0.8){
        scale(1/1.2,1/1.2);
        zoomFactor = newZoom;
    }
    qDebug() << zoomFactor;
}

void MyView::zoomIn() {
    double newZoom = zoomFactor*1.2;
    if(newZoom <= 2){
        scale(1.2,1.2);
        zoomFactor = newZoom;
    }
    qDebug() << zoomFactor;
}