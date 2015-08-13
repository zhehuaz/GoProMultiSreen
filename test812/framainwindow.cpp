#include "framainwindow.h"
#include "ui_framainwindow.h"

fraMainWindow::fraMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fraMainWindow)
{
    ui->setupUi(this);
    thread = new VideoCaptureThread;
    qRegisterMetaType< QVector<Mat> >("QVector<Mat>");
    connect(thread,SIGNAL(updateFrame(QVector<Mat>,bool)),this,SLOT(displayFrame(QVector<Mat>)));
    thread->start();
}

fraMainWindow::~fraMainWindow()
{
    delete ui;
}

void fraMainWindow::displayFrame(const QVector<Mat> &newFrame)
{
    if(newFrame.size() > 0)
        ui->video1->setPixmap(util.cvMatToQPixmap(newFrame[0]));
    if(newFrame.size() > 1)
        ui->video2->setPixmap(util.cvMatToQPixmap(newFrame[1]));
    if(newFrame.size() > 2)
        ui->video3->setPixmap(util.cvMatToQPixmap(newFrame[2]));
    if(newFrame.size() > 3)
        ui->video4->setPixmap(util.cvMatToQPixmap(newFrame[3]));
}

void fraMainWindow::on_start1btn_clicked()
{

}

void fraMainWindow::on_startallbtn_clicked()
{
}
