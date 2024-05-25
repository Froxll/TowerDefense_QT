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
    public slots:
        void startTimer();
        void updateTimer();
        void stopTimer();
        void renameButton2(const QString& newName);
    private:
        Button* button;
        Button* button2;
        QLabel* coinLabel;
        QLabel* timerLabel;
        QLabel* hpLabel;
        QTimer* timer;
        int time = 0;
    public:
        Banner(QWidget* parent = 0);
        ~Banner(){
            delete button;
            delete button2;
            delete coinLabel;
            delete timerLabel;
            delete hpLabel;
            delete timer;
        }
        Button* getButon(){
            return button;
        }
        Button* getButon2(){
            return button2;
        }
        QLabel* getCoinLabel(){
            return coinLabel;
        }
        QLabel* getHPLabel(){
            return hpLabel;
        }
        void setTime(int i){
            time = i;
        }
};

#endif //PROJETQT_BANNER_H
