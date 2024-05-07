#ifndef PROJETQT_BUTTON_H
#define PROJETQT_BUTTON_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>

class Button : public QWidget{
    Q_OBJECT
    private:
        QPushButton* button;
    public:
        Button(const QString& buttonText, QWidget* parent = 0);
        ~Button(){
            delete button;
        }
        QPushButton* getButton(){
            return button;
        }
};


#endif //PROJETQT_BUTTON_H
