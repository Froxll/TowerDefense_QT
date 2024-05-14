#include "MyScene.h"

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {
    //Intialisation du timer
    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);
    imagePath = QDir::currentPath()+"/../Image/TowerDefenseMap.png";
    background.load(imagePath);
    int newWidth = background.width();
    int newHeight = background.height();
    this->setSceneRect(0,0,newWidth,newHeight);
   // QString mapPath = QDir::currentPath()+"/../Image/TowerDefenseMap.png";
   // QPixmap map(mapPath);
   // this->setSceneRect(0,0,map.width() * 0.7,map.height() * 0.7);
}

MyScene::~MyScene() {
    delete timer;
}

void MyScene::update() {
    qDebug()<<"Animation update";
}

void MyScene::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    //QPixmap backgroundResize = background.scaled(newWidth,newHeight);

    if (background.isNull()) {
        qDebug() << "Erreur lors du chargement de l'image.";
    } else {
        painter->drawPixmap(QPointF(0, 0), background, sceneRect());
    }
}

void MyScene::addTower(const QPoint& position) {
    QGraphicsPixmapItem* towerItem = new QGraphicsPixmapItem(QPixmap(QDir::currentPath()+"/../Image/tour.png"));
    towerItem->setPos(position);
    addItem(towerItem);
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    qDebug() << "Click éffectué" << event->scenePos();
    QGraphicsScene::mousePressEvent(event);
    QPointF clickPos = event->scenePos();
    addTower(clickPos.toPoint());
    addGobelin();
}

void MyScene::addGobelin(){
    QGraphicsPixmapItem* gobItem = new QGraphicsPixmapItem(QPixmap(QDir::currentPath()+"/../Image/marche_bas_1.png"));
    int y = height(); // Récupération de la hauteur de la scène
    qDebug() << y;
    gobItem->setPos(100, y/2);
    addItem(gobItem);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        // Déplacement de l'image
        gobItem->moveBy(10, 0);

        // Vérification si la position en x dépasse 1000
        if (gobItem->pos().x() > 200) {
            // Arrêt du timer
            timer->stop();
        }
    });

    // Démarrage du timer
    timer->start(500); // 500 ms = 0.5 secondes
}