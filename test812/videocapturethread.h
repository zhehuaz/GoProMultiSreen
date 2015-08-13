#ifndef VIDEOCAPTURETHREAD_H
#define VIDEOCAPTURETHREAD_H
#include <QThread>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/core/core.hpp>
#include <QVector>

using namespace std;
using namespace cv;

class VideoCaptureThread : public QThread
{
    Q_OBJECT

    bool isRecording;
    VideoCapture *camera;
    int cameraNum;
public:
    VideoCaptureThread(int);
    ~VideoCaptureThread();
protected:
    void run();
signals:
    void updateFrame(const Mat& newFrame, int cameraNum);
};

#endif // VIDEOCAPTURETHREAD_H
