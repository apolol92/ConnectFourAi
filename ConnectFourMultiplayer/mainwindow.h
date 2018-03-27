#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QImage>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QPixmap>
#include <QSignalMapper>
#include "../untitled/connectfour.h"
#include "dlabel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onAddClicked(int num);



private:
    QSignalMapper *signalMapper;
    Ui::MainWindow *ui;
    QPixmap pxBlueDisk;
    QPixmap pxRedDisk;
    QPixmap pxEmptyDisk;
    QList<DLabel*> imgList;
    QList<QPushButton*> btList;
    ConnectFour cFour;
    void drawGame();
};

#endif // MAINWINDOW_H
