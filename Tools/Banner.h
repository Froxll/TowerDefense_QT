#ifndef PROJETQT_BANNER_H
#define PROJETQT_BANNER_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QTimer>

#include "../Character/Player.h"
#include "Button.h"

class Banner : public QWidget{
    Q_OBJECT
    private slots:
        void updateTimer();
    private:
        Button* button;
        Player* player;
        QLabel* coinLabel;
        QLabel* timerLabel;
        QTimer* timer;
        int time;
    public:
        Banner(QWidget* parent = 0);
        ~Banner(){
            delete button;
            delete coinLabel;
            delete timerLabel;
        }
};

#endif //PROJETQT_BANNER_H
