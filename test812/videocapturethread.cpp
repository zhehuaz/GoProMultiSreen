#include "videocapturethread.h"
#include <QDebug>
#include <opencv2/highgui/highgui.hpp>

VideoCaptureThread::VideoCaptureThread(int cameraNum = 0) : cameraNum(cameraNum)
{
    isRecording = false;
    camera = NULL;
    vWriter = NULL;

    //connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

VideoCaptureThread::~VideoCaptureThread()
{
    if(camera != NULL)
        delete camera;
    if(vWriter != NULL)
        delete vWriter;
}

void VideoCaptureThread::run()
{
    camera = new VideoCapture(cameraNum);

    if(camera != NULL && camera -> isOpened())
    {
        cameraIsOpen(cameraNum);
        cv::Mat src;
        //int k = 100;
        while(!this->isInterruptionRequested() )
        {
            for(int i = 0;i < 5;i ++)
            {
                *camera >> src;
            }
            if(!src.empty())
            {
                updateFrame(src, cameraNum);
                if(isRecording)
                    vWriter->write(src);
                src.release();
            }

            //qDebug() << k;

            QThread::usleep(0);
        }
    }
    qDebug() << "completed";
}

void VideoCaptureThread::startRecording()
{
    isRecording = true;
    stringstream temp;
    temp << cameraNum;

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString timestr = current_date_time.toString("yyyy-MM-dd hh.mm.ss");
    const string NAME = "result  " + temp.str() + timestr.toStdString() +".avi";

    if(camera->isOpened())
    {
        vWriter = new VideoWriter(NAME, CV_FOURCC('i', 'Y', 'U', 'V'), 15.,
                              Size(camera->get(CAP_PROP_FRAME_WIDTH), camera->get(CAP_PROP_FRAME_HEIGHT)), true);
    }
}

void VideoCaptureThread::stopRecording()
{
    isRecording = false;
    if(camera->isOpened())
    {
       vWriter->release();
    }
}

