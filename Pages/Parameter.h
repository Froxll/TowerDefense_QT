#ifndef PROJETQT_PARAMETER_H
#define PROJETQT_PARAMETER_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>

#include "../Tools/Slider.h"
#include "../Tools/Button.h"


class Parameter : public QMainWindow{
    Q_OBJECT
    private slots:
        void openMenu();
    private:
        Button* button;
        Slider* slider;
    public:
        Parameter(QWidget* parent = 0);
        ~Parameter(){
            delete button;
            delete slider;
        }
    signals:
        void openMenuClicked();
};

#endif //PROJETQT_PARAMETER_H
