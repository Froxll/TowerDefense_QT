#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow menu;
    menu.showFullScreen();

    return app.exec();
}
