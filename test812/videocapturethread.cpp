#include "videocapturethread.h"
#include <QDebug>
#include <opencv2/highgui/highgui.hpp>

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
    stringstream temp;
    temp << cameraNum;
    const string NAME = "result" + temp.str() +".avi";


    if(camera != NULL && camera -> isOpened())
    {
        vWriter = new VideoWriter(NAME, CV_FOURCC('i', 'Y', 'U', 'V'), 15.,
                                  Size(camera->get(CAP_PROP_FRAME_WIDTH), camera->get(CAP_PROP_FRAME_HEIGHT)), true);
        if(!vWriter->isOpened())
            qDebug() << " Open file error";
        cv::Mat src;
        //int k = 100;
        while(QThread::isRunning())
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

            //QThread::usleep(33);
        }
        qDebug() << "completed";
        vWriter->release();

    }
}

void VideoCaptureThread::startRecording()
{
    isRecording = true;
    qDebug() << "start recording";
}


