#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    this->setWindowTitle("Medieval Tower Defense Super Marvelous Enjoyable Game");
    this->resize(900,600);
    QSize mainWindowSize = QSize(900,600);

    banner = new Banner(this);
    mainScene = new MyScene(mainWindowSize,this);
    mainView = new MyView(this);
    mainView->setScene(mainScene);

    banner->getCoinLabel()->setText("Coins : " + QString::number(mainScene->getPlayer()->getCoin()));
    banner->getHPLabel()->setText("HP : " + QString::number(mainScene->getPlayer()->getHP()));
    connect(mainScene, &MyScene::coinValueChanged,this,&MainWindow::updateCoinLabel);
    connect(mainScene, &MyScene::hpValueChanged,this,&MainWindow::updateHPLabel);

    connect(mainScene, &MyScene::GameEnd,banner,&Banner::stopTimer);
    connect(mainScene, &MyScene::GameEnd,[this]{
        banner->renameButton2("REJOUER");
        banner->setTime(0);
        });

    connect(banner->getButon()->getButton(), &QPushButton::clicked, [this]{
        this->close();
        });
    connect(banner->getButon2()->getButton(), &QPushButton::clicked, [this] {
        auto& enemyList = mainScene->getEnemy();
        if(enemyList.empty()){
            banner->renameButton2("JOUER");
            auto& towerList = mainScene->getTower();
            if(!towerList.empty()){
                for(Tower* t : towerList){
                    mainScene->removeItem(t);
                    mainScene->removeItem(t->getRangeItem());
                }
                mainScene->getTower().clear();
                qDebug() << mainScene->getTower().size();
            }
            mainScene->getPlayer()->setHP();
            mainScene->getPlayer()->setCoin();
            emit mainScene->hpValueChanged(mainScene->getPlayer()->getHP());
            emit mainScene->coinValueChanged(mainScene->getPlayer()->getCoin());
            mainScene->gameEnd(false);
            mainScene->launchWave(1);
            mainScene->isPressed();
        }
    });

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


    QTimer::singleShot(100, this, [=]() {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_E, Qt::NoModifier);
        QApplication::postEvent(this, event);
    });
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

void MainWindow::updateCoinLabel(int newCoin) {
    banner->getCoinLabel()->setText("Coins : "+ QString::number(newCoin));
}

void MainWindow::updateHPLabel(int newHP) {
    banner->getHPLabel()->setText("HP : " + QString::number(newHP));
}