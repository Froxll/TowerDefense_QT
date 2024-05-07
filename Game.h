#ifndef PROJETQT_GAME_H
#define PROJETQT_GAME_H

#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Banner.h"

class Game : public QMainWindow{
    Q_OBJECT
    private slots:
        void openMenu();
    private:
        Banner* banner;
    public:
        Game(QWidget* parent = 0);
        ~Game(){
            delete banner;
        }
    signals:
        void openMenuClicked();
};

#endif //PROJETQT_GAME_H
