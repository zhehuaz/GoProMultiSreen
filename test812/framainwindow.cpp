#include "framainwindow.h"
#include "ui_framainwindow.h"
#include <QDebug>
fraMainWindow::fraMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fraMainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<Mat>("Mat");

    ui->treeWidget->setHeaderLabel(tr("设备管理"));
    ui->treeWidget->setColumnCount(1);
    item1 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("摄像机")));
    item1 -> setIcon(0,QIcon("camera.png"));

    connect(ui->startAllBtn,SIGNAL(clicked(bool)),this,SLOT(startRecording()));
    connect(ui->stopbtn,SIGNAL(clicked(bool)),this,SLOT(stopRecording()));
    connect(ui->quitbtn,SIGNAL(clicked(bool)),this,SLOT(close()));

    for(int i = 0;i < 4;i ++)
    {
        thread[i] = new VideoCaptureThread(i);
        connect(thread[i],SIGNAL(updateFrame(Mat, int)),this,SLOT(displayFrame(Mat, int)));
        connect(ui->stopbtn,SIGNAL(clicked(bool)),thread[i],SLOT(stopRecording()));
        connect(ui->startAllBtn, SIGNAL(clicked(bool)),thread[i], SLOT(startRecording()));
        connect(thread[i],SIGNAL(cameraIsOpen(int)),this,SLOT(addTreeWidgetItem(int)));
        //connect(this,SIGNAL(destroyed(QObject*)),thread[i],SLOT(stop()));
        //connect(thread[i], SIGNAL(finished()), thread[i], SLOT(deleteLater()));
        thread[i]->start();
    }
}

fraMainWindow::~fraMainWindow()
{
    delete ui;
    delete item1;
    for(int i = 0;i < 4;i ++)
    {
        if (thread[i] != 0 && thread[i]->isRunning() ) {
            thread[i]->requestInterruption();
            thread[i]->wait();
            delete thread[i];
        }
    }
}

void fraMainWindow::displayFrame(const Mat &newFrame, int cameraNum)
{
    QPixmap newPixmap = QPixmap::fromImage(
                QImage(
                    newFrame.data,
                    newFrame.cols,
                    newFrame.rows,
                    newFrame.step,
                    QImage::Format_RGB888).rgbSwapped());
    switch(cameraNum)
    {
    case 0:
        ui->video1->setPixmap(newPixmap);
        //qDebug() << "Video 1 received frame";
        break;
    case 1:
        ui->video2->setPixmap(newPixmap);
        //qDebug() << "Video 2 received frame";
        break;
    case 2:
        ui->video3->setPixmap(newPixmap);
        //qDebug() << "Video 3 received frame";
        break;
    case 3:
        ui->video4->setPixmap(newPixmap);
        //qDebug() << "Video 4 received frame";
        break;

    }
}

void fraMainWindow::addTreeWidgetItem(int cameraNum)
{
    QString s = "摄像机  " + QString::number(cameraNum+1);


    //QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1,QStringList(QString("name")));
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1,QStringList(s));
}
void fraMainWindow::startRecording()
{
    ui->startAllBtn->setEnabled(false);
    ui->stopbtn->setEnabled(true);
    ui->quitbtn->setEnabled(false);
}

void fraMainWindow::stopRecording()
{
    ui->startAllBtn->setEnabled(true);
    ui->stopbtn->setEnabled(false);
    ui->quitbtn->setEnabled(true);
}
