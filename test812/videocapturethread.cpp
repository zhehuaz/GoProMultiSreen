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
    CV_FOURCC('M', 'J', 'P', 'G');

    if(camera != NULL && camera -> isOpened())
    {
        vWriter = new VideoWriter(NAME, -1, 10.,
                                  Size(camera->get(CAP_PROP_FRAME_WIDTH), camera->get(CAP_PROP_FRAME_HEIGHT)), true);
        if(!vWriter->isOpened())
            qDebug() << " Open file error";
        cv::Mat src;
        //int k = 200;
        while(1)
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
                vWriter->release();

            }

            //qDebug() << k;

            //QThread::usleep(33);
        }
        qDebug() << "completed";

    }
}

void VideoCaptureThread::startRecording()
{
    isRecording = true;
    qDebug() << "start recording";
}


