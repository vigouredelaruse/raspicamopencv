#ifndef CONSOLECAPTURE_H
#define CONSOLECAPTURE_H

#include <QObject>
#include <QtWidgets>
#include <opencv2/opencv.hpp>
#ifdef __linux__
#include <raspicam/raspicam_cv.h>
#endif
#ifdef __APPLE_CC__
#include "TargetConditionals.h"
    #ifdef TARGET_OS_MAC
        #include <GLUT/glut.h>
        #include <OpenGL/OpenGL.h>
    #endif

#endif
#include <opencv2/opencv.hpp>

class ConsoleCapture : public QObject
{
    Q_OBJECT
    QBasicTimer m_timer;
#ifdef __linux__
    QScopedPointer<raspicam::RaspiCam_Cv> m_videoCapture;
#elif __APPLE_CC__
    QScopedPointer<cv::VideoCapture> m_videoCapture;
#endif
public:
    explicit ConsoleCapture(QObject *parent = 0);
signals:
    void started();
    void matReady(const cv::Mat &);
public slots:
    void start();
    void stop();
private:
    void timerEvent(QTimerEvent *ev);
#ifdef __linux__
    raspicam::RaspiCam_Cv cam;
#endif
};

#endif // CONSOLECAPTURE_H
