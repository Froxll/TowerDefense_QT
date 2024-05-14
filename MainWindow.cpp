#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    mainScene = new MyScene(this);
    mainView = new MyView(this);
    mainView->setScene(mainScene);
    this->setCentralWidget(mainView);

    this->setWindowTitle("Medieval Tower Defense Super Marvelous Enjoyable Game");
    this->resize(1920,1080);

    //helpMenu = menuBar()->addMenu(tr("&Help"));
    //QAction* actionHelp = new QAction(tr("&About"), this);
    //connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    //helpMenu->addAction(actionHelp);
}

MainWindow::~MainWindow(){
}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}