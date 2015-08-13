#-------------------------------------------------
#
# Project created by QtCreator 2015-08-12T13:45:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test812
TEMPLATE = app


SOURCES += main.cpp\
        framainwindow.cpp \
    utils.cpp \
    videocapturethread.cpp

HEADERS  += framainwindow.h \
    utils.h \
    videocapturethread.h

FORMS    += framainwindow.ui

INCLUDEPATH+=C:\OpenCV\include\opencv\
                    C:\OpenCV\include\opencv2\
                    C:\OpenCV\include

LIBS+=C:\OpenCV\lib\libopencv_videostab300.dll.a\
        C:\OpenCV\lib\libopencv_calib3d_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_calib3d300.dll.a\
        C:\OpenCV\lib\libopencv_core_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_core300.dll.a\
        C:\OpenCV\lib\libopencv_features2d_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_features2d300.dll.a\
        C:\OpenCV\lib\libopencv_flann_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_flann300.dll.a\
        C:\OpenCV\lib\libopencv_hal_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_hal300.a\
        C:\OpenCV\lib\libopencv_highgui_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_highgui300.dll.a\
        C:\OpenCV\lib\libopencv_imgcodecs_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_imgcodecs300.dll.a\
        C:\OpenCV\lib\libopencv_imgproc_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_imgproc300.dll.a\
        C:\OpenCV\lib\libopencv_ml_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_ml300.dll.a\
        C:\OpenCV\lib\libopencv_objdetect_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_objdetect300.dll.a\
        C:\OpenCV\lib\libopencv_perf_calib3d_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_core_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_features2d_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_imgcodecs_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_imgproc_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_objdetect_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_photo_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_stitching_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_superres_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_video_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_perf_videoio_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_photo_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_photo300.dll.a\
        C:\OpenCV\lib\libopencv_shape_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_shape300.dll.a\
        C:\OpenCV\lib\libopencv_stitching_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_stitching300.dll.a\
        C:\OpenCV\lib\libopencv_superres_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_superres300.dll.a\
        C:\OpenCV\lib\libopencv_test_calib3d_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_core_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_features2d_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_flann_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_highgui_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_imgcodecs_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_imgproc_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_ml_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_objdetect_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_photo_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_shape_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_stitching_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_superres_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_video_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_test_videoio_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_ts_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_ts300.a\
        C:\OpenCV\lib\libopencv_video_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_video300.dll.a\
        C:\OpenCV\lib\libopencv_videoio_pch_dephelp.a\
        C:\OpenCV\lib\libopencv_videoio300.dll.a
