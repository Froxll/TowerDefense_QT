#ifndef PROJETQT_MYVIEW_H
#define PROJETQT_MYVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>
#include <QMouseEvent>

class MyView : public QGraphicsView {
    Q_OBJECT
    private:
        double zoomFactor = 1.0;
    protected:
        void resizeEvent(QResizeEvent* event) override;
    public:
        MyView(QWidget* parent = nullptr);
        void zoomIn();
        void zoomOut();
};

#endif //PROJETQT_MYVIEW_H
