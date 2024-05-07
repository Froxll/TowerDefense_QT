#ifndef PROJETQT_SLIDER_H
#define PROJETQT_SLIDER_H

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QHBoxLayout>

class Slider : public QWidget{
    Q_OBJECT
    private:
        QSlider* slider;
    public:
        Slider(QWidget* parent = 0);
        ~Slider(){
            delete slider;
        }
        QSlider* getSlider(){
            return slider;
        }
};

#endif //PROJETQT_SLIDER_H
