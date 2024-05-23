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
#include <QVBoxLayout>

#include "Character/Player.h"
#include "MyView.h"
#include "MyScene.h"
#include "Constructions/Tower.h"
#include "Tools/Banner.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    protected:
        void keyPressEvent(QKeyEvent* event) override;
    private :
        Banner* banner;
        Player* player;
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
