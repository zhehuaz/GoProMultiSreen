#ifndef UTILS_H
#define UTILS_H

#include <QImage>
#include <QPixmap>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include <opencv2/core/core.hpp>

class Utils
{
public:
   // Utils();
    QImage cvMatToQImage( const cv::Mat &inMat );
    QPixmap cvMatToQPixmap( const cv::Mat &inMat );

};


#endif // UTILS_H
