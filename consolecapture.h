#ifndef CONSOLECAPTURE_H
#define CONSOLECAPTURE_H

#include <QObject>
#include <QtWidgets>
#include <opencv2/opencv.hpp>
#include <raspicam/raspicam_cv.h>

class ConsoleCapture : public QObject
{
    Q_OBJECT
    QBasicTimer m_timer;
    QScopedPointer<raspicam::RaspiCam_Cv> m_videoCapture;
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

    raspicam::RaspiCam_Cv cam;
};

#endif // CONSOLECAPTURE_H
