#include "videocapturethread.h"

VideoCaptureThread::VideoCaptureThread()
{
}

void VideoCaptureThread::run()
{
    cameras[0] = new VideoCapture(0);
    cameras[1] = new VideoCapture(1);

    //cv::Mat res;
    QVector<Mat> mats;
    cv::Mat src;
    while(1)
    {
        mats.clear();
        for(int i = 0;i < 4;i ++)
        {
            if(cameras[i] != NULL && cameras[i] -> isOpened())
            {
                *cameras[i] >> src;
                mats.push_back(src);            
                src.release();
            }
        }
        updateFrame(mats,false);
        QThread::sleep(100);
    }
}

 void updateFrame(const QVector<Mat> &newFrame , bool isRecording)
 {

 }


