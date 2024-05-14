#ifndef PROJETQT_MYVIEW_H
#define PROJETQT_MYVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>
#include <QMouseEvent>

class MyView : public QGraphicsView {
    Q_OBJECT
    protected:
        void resizeEvent(QResizeEvent* event) override;
    public:
        MyView(QWidget* parent = nullptr);
};

#endif //PROJETQT_MYVIEW_H
