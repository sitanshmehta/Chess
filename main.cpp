#include "mainwindow.h"
#include "square.h"
#include "board.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    //Square square(0, 0);
    //square.show();

    Board board;
    board.show();
    return a.exec();
}
