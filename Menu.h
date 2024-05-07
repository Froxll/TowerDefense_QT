#ifndef PROJETQT_MENU_H
#define PROJETQT_MENU_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>

#include "Game.h"
#include "Parameter.h"
#include "Button.h"

class Menu : public QMainWindow{
    Q_OBJECT
    private slots:

    private:
        Button* button1;
        Button* button2;
        Button* button3;
        Parameter* parameter;
        Game* game;
    public:
        Menu(QWidget* parent = 0);
        void showGame(){
            game->show();
        }
        void showPara(){
            parameter->show();
        }
        void closeWindow(){
            close();
        }
        ~Menu(){
            delete button1;
            delete button2;
            delete button3;
            delete parameter;
        }
};

#endif //PROJETQT_MENU_H
