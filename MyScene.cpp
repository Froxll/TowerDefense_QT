#include "MyScene.h"

MyScene::MyScene(const QSize& size, QObject* parent) : QGraphicsScene(parent) {
    //Intialisation du timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(update()));
    timer->start(30);
    imagePath = QDir::currentPath()+"/../Image/TowerDefenseMap.png";
    background.load(imagePath);
    setSceneRect(0, 0, background.width(), background.height());
    player = new Player();
}

void MyScene::EnemyTouch(Enemy* e){
    if(this->getEndGame() != true){
        static int call = 0;
        if(call % 2 == 0){
            for(Tower* t : list_of_tower) {
                qreal distance = ::sqrt(::pow(e->x() - t->x(), 2) + ::pow(e->y() - t->y(), 2));
                if(e->getHP() < 0){
                    t->setTarget(0);
                }
                if (distance <= 150 and t->getTarget() < 1 and e->getDead() != true) {
                    t->setTarget(1);
                    qDebug() << "Enemy touché";
                    e->addHP(t->getDamage());
                    if (e->getHP() <= 0) {
                        qDebug() << "mort";
                        e->setDead();
                        this->removeItem(e);
                        auto new_end = std::remove(list_of_enemy.begin(), list_of_enemy.end(), e);
                        list_of_enemy.erase(new_end, list_of_enemy.end());
                        player->addCoin(2);
                        emit coinValueChanged(player->getCoin());
                    }
                }
                else{
                    t->setTarget(0);
                }
            }
        }
        call++;
    }
}

MyScene::~MyScene() {
    delete timer;
}

void MyScene::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    if (background.isNull()) {
        qDebug() << "Erreur lors du chargement de l'image.";
    } else {
        painter->drawPixmap(QPointF(0, 0), background, sceneRect());
    }
}

void MyScene::isPressed() {
    bouttonPressed = true;
}

void MyScene::addTower(QPoint position) {
    qDebug() << player->getCoin();
    if(player->getCoin() >= 50){
        player->substractCoin(50);
        emit coinValueChanged(player->getCoin());
        if((position.y() > 100 && position.y() < 200 && position.x() > 0 && position.x() < 800)
           ||(position.y() > 300 && position.y() < 400 && position.x() > 0 && position.x() < 700)
           ||(position.y() > 300 && position.y() < 600 && position.x() > 600 && position.x() < 700)
           ||(position.y() > 500 && position.y() < 1010 && position.x() > 500 && position.x() < 600)
           ||(position.y() > -50 && position.y() < 600 && position.x() > 800 && position.x() < 900)
           ||(position.y() > 500 && position.y() < 600 && position.x() > 900 && position.x() < 1400)
           ||(position.y() > 800 && position.y() < 1010 && position.x() > 700 && position.x() < 800)
           ||(position.y() > 700 && position.y() < 800 && position.x() > 800 && position.x() < 2000)
           ||(position.y() > -50 && position.y() < 500 && position.x() > 1000 && position.x() < 100)
           ||(position.y() > 300 && position.y() < 400 && position.x() > 1100 && position.x() < 1500)
           ||(position.y() > 400 && position.y() < 700 && position.x() > 1500 && position.x() < 1600)
           ||(position.y() > 500 && position.y() < 600 && position.x() > 1600 && position.x() < 2000)){

            bool addTower = true;

            qreal rangeDiameter = 2 * 150;

            if(!(list_of_tower.empty())){
                for(Tower* t : list_of_tower){
                    qreal distance = ::sqrt(::pow(position.x()- t->x() ,2) + ::pow(position.y() - t->y(),2));
                    if(distance <= 150){
                        addTower = false;
                        qDebug() << "Click Refusé";
                    }
                }
            }
            if(addTower == true || list_of_tower.empty()){
                Tower* newTower = new Tower();
                newTower->moveBy(position.x(), position.y());

                addItem(newTower);

                //Calcul des coordonnées pour centrer la portée autour de la tour
                qreal rangeX = position.x() - newTower->getRange() + newTower->boundingRect().width() / 2;
                qreal rangeY = position.y() - newTower->getRange() + newTower->boundingRect().height() / 2;

                //Affichage de la range de la tour
                QGraphicsEllipseItem* rangeItem = new QGraphicsEllipseItem(QRectF(rangeX, rangeY, rangeDiameter, rangeDiameter));
                rangeItem->setPen(QPen(Qt::black, 1, Qt::SolidLine));
                newTower->setRangeItem(rangeItem);
                addItem(rangeItem);

                // Ajout de la tour dans la liste des tours
                list_of_tower.push_back(newTower);
                qDebug() << "Tour ajouté";
            }
        }
    }
    else{
        qDebug() << "Pas assez de sous";
    }
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if(bouttonPressed == true and this->getEndGame() != true){
        static int time = 1;
        QGraphicsScene::mousePressEvent(event);
        QPointF sizeTower(28.0,86.0);
        QPointF clickPos = event->scenePos() - sizeTower;
        addTower(clickPos.toPoint());
        qDebug() << "Click détecté" << time;
        time++;
    }
}

void MyScene::addGobelinGauche(){
    if(this->getEndGame() != true){
        Enemy* gobItem = new Enemy();
        list_of_enemy.push_back(gobItem);   //ajoute gobelin au vector enemies

        int gob_largeur = 60;
        int gob_hauteur = 70;

        int y = height();
        y = y / 2;

        gobItem->setPos(0, y / 2);
        addItem(gobItem);

        QTimer* timer1 = new QTimer(this);
        connect(timer1, &QTimer::timeout, [this, gobItem, gob_largeur, gob_hauteur, timer1]() {
            gobItem->moveBy(10, 0);
            EnemyTouch(gobItem);
            if (gobItem->pos().x() > (width() * 0.375 - gob_largeur)) {
                timer1->stop();
                timer1->deleteLater();

                QTimer* timer2 = new QTimer(this);
                connect(timer2, &QTimer::timeout, [this, gobItem, gob_hauteur, timer2]() {
                    gobItem->moveBy(0, 10);
                    EnemyTouch(gobItem);
                    if (gobItem->pos().y() > (height() * 0.681) - gob_hauteur) {
                        timer2->stop();
                        timer2->deleteLater();

                        QTimer* timer3 = new QTimer(this);
                        connect(timer3, &QTimer::timeout, [this, gobItem, timer3]() {
                            gobItem->moveBy(10, 0);
                            EnemyTouch(gobItem);
                            if (gobItem->pos().x() > width()) {
                                timer3->stop();
                                timer3->deleteLater();
                                if(gobItem->getDead() != true and this->getEndGame() != true and player->getHP() > 0){
                                    player->addHP(50);
                                    emit hpValueChanged(player->getHP());
                                    if(player->getHP() == 0){
                                        this->gameEnd(true);
                                        emit GameEnd();
                                    }
                                }
                                this->removeItem(gobItem);
                                auto gobelin = find(list_of_enemy.begin(), list_of_enemy.end(), gobItem);
                                if (gobelin != list_of_enemy.end()) {
                                    list_of_enemy.erase(gobelin);
                                }
                                delete gobItem;
                            }
                        });
                        timer3->start(100); // 0.1s
                    }
                });
                timer2->start(100); // 0.1s
            }
        });

        timer1->start(100); // 0.1s
    }
}

void MyScene::addGobelinHaut(){
    if(this->getEndGame() != true){
        Enemy* gobItem = new Enemy();
        list_of_enemy.push_back(gobItem); // Ajouter le gobelin au vecteur des ennemis

        int gob_largeur = 60;
        int gob_hauteur = 70;

        int x = width();
        x = 0.475 * x;
        x = x - gob_largeur / 2;

        gobItem->setPos(x, 0);
        addItem(gobItem);

        QTimer* timer1 = new QTimer(this);
        connect(timer1, &QTimer::timeout, [this, gobItem, gob_largeur, gob_hauteur, timer1]() {
            gobItem->moveBy(0, 10);
            EnemyTouch(gobItem);
            if (gobItem->pos().y() > (height() * 0.5) - gob_hauteur) {
                timer1->stop();
                timer1->deleteLater();

                QTimer* timer2 = new QTimer(this);
                connect(timer2, &QTimer::timeout, [this, gobItem, gob_largeur, gob_hauteur, timer2]() {
                    gobItem->moveBy(10, 0);
                    EnemyTouch(gobItem);
                    if (gobItem->pos().x() > (width() * 0.725) - gob_largeur / 2) {
                        timer2->stop();
                        timer2->deleteLater();

                        QTimer* timer3 = new QTimer(this);
                        connect(timer3, &QTimer::timeout, [this, gobItem, gob_hauteur, timer3]() {
                            gobItem->moveBy(0, 10);
                            EnemyTouch(gobItem);
                            if (gobItem->pos().y() > (height() * 0.681) - gob_hauteur) {
                                timer3->stop();
                                timer3->deleteLater();

                                QTimer* timer4 = new QTimer(this);
                                connect(timer4, &QTimer::timeout, [this, gobItem, timer4]() {
                                    gobItem->moveBy(10, 0);
                                    EnemyTouch(gobItem);
                                    if (gobItem->pos().x() > width()) {
                                        timer4->stop();
                                        timer4->deleteLater();
                                        if(gobItem->getDead() != true and this->getEndGame() != true and player->getHP() > 0){
                                            player->addHP(50);
                                            emit hpValueChanged(player->getHP());
                                            if(player->getHP() == 0){
                                                this->gameEnd(true);
                                                emit GameEnd();
                                            }
                                        }
                                        this->removeItem(gobItem);
                                        auto gobelin = find(list_of_enemy.begin(), list_of_enemy.end(), gobItem);
                                        if (gobelin != list_of_enemy.end()) {
                                            list_of_enemy.erase(gobelin);
                                        }
                                        delete gobItem;
                                    }
                                });
                                timer4->start(100); // 0.1s
                            }
                        });
                        timer3->start(100); // 0.1s
                    }
                });
                timer2->start(100); // 0.1s
            }
        });
        timer1->start(100); // 0.1s
    }
}

void MyScene::addGobelinBas(){
    if(this->getEndGame() != true){
        Enemy* gobItem = new Enemy();
        list_of_enemy.push_back(gobItem); // Ajouter le gobelin au vecteur des ennemis

        int gob_largeur = 60;
        int gob_hauteur = 70;

        int x = width();
        x = 0.32 * x;
        x = x - gob_largeur / 2;
        int y = height();
        y = y - 20;

        gobItem->setPos(x, y);
        addItem(gobItem);

        QTimer* timer1 = new QTimer(this);
        connect(timer1, &QTimer::timeout, [this, gobItem, gob_hauteur, timer1]() {
            gobItem->moveBy(0, -10);
            EnemyTouch(gobItem);
            if (gobItem->pos().y() < (height() * 0.68) - gob_hauteur) {
                timer1->stop();

                QTimer* timer2 = new QTimer(this);
                connect(timer2, &QTimer::timeout, [this, gobItem, timer2]() {
                    gobItem->moveBy(10, 0);
                    EnemyTouch(gobItem);
                    if (gobItem->pos().x() > width()) {
                        timer2->stop();
                        if(gobItem->getDead() != true and this->getEndGame() != true and player->getHP() > 0){
                            player->addHP(50);
                            emit hpValueChanged(player->getHP());
                            if(player->getHP() == 0){
                                this->gameEnd(true);
                                emit GameEnd();
                            }
                        }
                        this->removeItem(gobItem);      //supprime le gobelin visuellement
                        auto gobelin = find(list_of_enemy.begin(), list_of_enemy.end(), gobItem);       //cherche si le gobelin est dans le vecteur
                        if (gobelin != list_of_enemy.end()) {                                           //s'il est dans le vecteur
                            list_of_enemy.erase(gobelin);                                               //alors on le supprime
                        }
                        delete gobItem;                                                                 //puis on supprime gobItem de la mémoire
                    }
                });
                timer2->start(100); // 0.1s
            }
        });

        timer1->start(100); // 0.1s
    }
}

void MyScene::launchWave(int waveNumber) {
    if(this->getEndGame() != true){
        int nb_ennemy = waveNumber * 3;
        qDebug() << "La difficulté (waveNumber) est la suivante : " << waveNumber;
        addEnemies(waveNumber, nb_ennemy);
    }
}

void MyScene::addEnemies(int waveNumber, int nb_ennemy) {
    for (int i = 0; i < nb_ennemy; ++i) {
        enemy_queue.push_back([this]() {
            int randNum = (rand() * 1.0 / RAND_MAX * 3) + 1;
            if (randNum == 1) {
                addGobelinBas();
                //qDebug() << "addGobelinBas appelé";
            } else if (randNum == 2) {
                addGobelinHaut();
                //qDebug() << "addGobelinHaut appelé";
            } else if (randNum == 3) {
                addGobelinGauche();
                //qDebug() << "addGobelinGauche appelé";
            }
        });
    }
    processEnemyQueue(waveNumber);
}

void MyScene::processEnemyQueue(int waveNumber) {
    if (!enemy_queue.empty()) {
        enemy_queue.front()();
        enemy_queue.pop_front();
        QTimer::singleShot(500, this, [this, waveNumber]() {
            processEnemyQueue(waveNumber);
        });
    }
    else {
        QTimer::singleShot(5000, this, [this, waveNumber]() {
            int newWaveNumber = waveNumber + 1;
            launchWave(newWaveNumber);

            //printEnemies(list_of_enemy);
        });
    }
}