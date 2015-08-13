#include "videocapturethread.h"
#include <QDebug>

VideoCaptureThread::VideoCaptureThread(int cameraNum = 0) : cameraNum(cameraNum)
{
    isRecording = false;
    camera = NULL;
}

VideoCaptureThread::~VideoCaptureThread()
{
    delete camera;
}

void VideoCaptureThread::run()
{
    camera = new VideoCapture(cameraNum);

    //cv::Mat res;
    cv::Mat src;
    if(camera != NULL && camera -> isOpened())
        while(1)
        {
            for(int i = 0;i < 5;i ++)
            {
                *camera >> src;
            }
            updateFrame(src, cameraNum);
            src.release();

            qDebug() << "updated frame sent";

            //QThread::usleep(33);
        }
}


