#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    this->setWindowTitle("Medieval Tower Defense Super Marvelous Enjoyable Game");
    this->resize(900,600);
    QSize mainWindowSize = QSize(900,600);

    banner = new Banner(this);
    player = new Player();
    mainScene = new MyScene(mainWindowSize,this);
    mainView = new MyView(this);
    mainView->setScene(mainScene);

    connect(banner->getButon()->getButton(), &QPushButton::clicked, [this]{
        this->close();
        });
    connect(banner->getButon2()->getButton(), &QPushButton::clicked, [this] { mainScene->launchWave(1);});

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(banner);
    layout->addWidget(mainView);
    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);
}

MainWindow::~MainWindow(){
    delete mainScene;
    delete mainView;
}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A:
            mainView->zoomIn();
            break;
        case Qt::Key_E:
            mainView->zoomOut();
            break;
        default:
            QMainWindow::keyPressEvent(event);
    }
}