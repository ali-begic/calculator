#include "mainwindow.h"

#include <muParser.h>

#include <QApplication>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;

    window.setWindowIcon(QIcon(":/icons/calculator.ico"));
    window.setWindowTitle("Calculator - by AliTech Works");
    window.setFixedSize(330,510);

    window.show();
    return app.exec();
}
