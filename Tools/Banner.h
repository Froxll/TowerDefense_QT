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
        void startTimer();
        void updateTimer();
    private:
        Button* button;
        Button* button2;
        QLabel* coinLabel;
        QLabel* timerLabel;
        QTimer* timer;
        int time = 0;
    public:
        Banner(QWidget* parent = 0);
        ~Banner(){
            delete button;
            delete button2;
            delete coinLabel;
            delete timerLabel;
        }
        Button* getButon(){
            return button;
        }
        Button* getButon2(){
            return button2;
        }
};

#endif //PROJETQT_BANNER_H
