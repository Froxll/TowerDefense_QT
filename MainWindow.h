#ifndef CPP_QT_TPMINIPROJET_MAINWINDOW_H
#define CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QMouseEvent>
#include <QVector>

#include "MyView.h"
#include "MyScene.h"
#include "Constructions/Tower.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    private :
        MyScene* mainScene;
        MyView* mainView;
        QMenu* helpMenu;
    public:
        MainWindow(QWidget* parent = nullptr);
        virtual ~MainWindow();
    public slots:
        void slot_aboutMenu();
};


#endif //CPP_QT_TPMINIPROJET_MAINWINDOW_H
