#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->pxBlueDisk = QPixmap("../assets/blue_disk.png");
    this->pxRedDisk = QPixmap("../assets/red_disk.png");
    this->pxEmptyDisk = QPixmap("../assets/empty_disk.png");
    ui->setupUi(this);

    for(int r = 0; r < 6; r++)
    {
        for(int c = 0; c < 7; c++)
        {

            DLabel *lab = new DLabel(r,c);
            lab->setGeometry(0,0,100,100);

            lab->setPixmap(this->pxEmptyDisk);
            ui->mGridLayout->addWidget(lab,r,c);
            this->imgList.append(lab);
        }
    }
    signalMapper = new QSignalMapper(this);
    for(int r = 6, c=0; c <7;c++)
    {
        QPushButton *btn = new QPushButton("Add");



        connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(btn, c);
        ui->mGridLayout->addWidget(btn,r,c);
        this->btList.append(btn);


    }
    connect(signalMapper, SIGNAL(mapped(int)),
                this, SLOT(onAddClicked(int)));




}

void MainWindow::onAddClicked(int num)
{
    if(cFour.putFieldInCol(num,cFour.currentTurn())==true)
    {
        QList<Field> fs = cFour.fields;

        //TODO
        for(int i = 0; i < fs.length(); i++)
        {
            for(int d = 0; d < this->imgList.length(); d++)
            {
                qDebug() << fs[i].getGridRow() << " " << fs[i].getGridCol() << " " << this->imgList[d]->row << this->imgList[d]->col;
                if(fs[i].getGridRow() == this->imgList[d]->row && fs[i].getGridCol() == this->imgList[d]->col)
                {
                    if(fs[i].getColor()==color::blue)
                    {
                        this->imgList[d]->setPixmap(this->pxBlueDisk);

                    }
                    else
                    {
                        this->imgList[d]->setPixmap(this->pxRedDisk);

                    }
                    break;
                }
            }
        }
        if(this->cFour.isGameFinished()==color::blue)
        {
            QMessageBox::information(
                this,
                ("Game finished!"),
                ("Blue wins!") );
            for(int i = 0; i < this->imgList.length(); i++)
            {
                this->imgList[i]->setPixmap(this->pxEmptyDisk);
            }
            this->cFour.reset();
        }
        else if(this->cFour.isGameFinished()==color::red)
        {
            QMessageBox::information(
                this,
                ("Game finished!"),
                ("Red wins!") );
            for(int i = 0; i < this->imgList.length(); i++)
            {
                this->imgList[i]->setPixmap(this->pxEmptyDisk);
            }
            this->cFour.reset();
        }
        else if(this->cFour.isGameFinished()==2){
            QMessageBox::information(
                this,
                ("Game finished!"),
                ("Undecided!") );
            for(int i = 0; i < this->imgList.length(); i++)
            {
                this->imgList[i]->setPixmap(this->pxEmptyDisk);
            }
            this->cFour.reset();
        }

    }


}

void MainWindow::drawGame()
{

}


MainWindow::~MainWindow()
{
    delete ui;
}
