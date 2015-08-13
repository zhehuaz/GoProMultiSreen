#include "framainwindow.h"
#include "ui_framainwindow.h"
#include <QDebug>
fraMainWindow::fraMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fraMainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<Mat>("Mat");


    for(int i = 0;i < 4;i ++)
    {
        thread[i] = new VideoCaptureThread(i);
        connect(thread[i],SIGNAL(updateFrame(Mat, int)),this,SLOT(displayFrame(Mat, int)));
        thread[i]->start();
    }
}

fraMainWindow::~fraMainWindow()
{
    delete ui;
    for(int i = 0;i < 4;i ++)
    {
        thread[i]->quit();
    }
    delete [] thread;
}

void fraMainWindow::displayFrame(const Mat &newFrame, int cameraNum)
{
    switch(cameraNum)
    {
    case 0:
        ui->video1->setPixmap(util.cvMatToQPixmap(newFrame));
        qDebug() << "Video 1 received frame";
        break;
    case 1:
        ui->video2->setPixmap(util.cvMatToQPixmap(newFrame));
        qDebug() << "Video 2 received frame";
        break;
    case 2:
        ui->video3->setPixmap(util.cvMatToQPixmap(newFrame));
        qDebug() << "Video 3 received frame";
        break;
    case 3:
        ui->video4->setPixmap(util.cvMatToQPixmap(newFrame));
        qDebug() << "Video 4 received frame";
        break;

    }
}

void fraMainWindow::on_start1btn_clicked()
{

}

void fraMainWindow::on_startallbtn_clicked()
{
}
