#ifndef ACQUISITIONCONVERTER_H
#define ACQUISITIONCONVERTER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/opencv.hpp>

class AcquisitionConverter : public QObject
{
    Q_OBJECT
public:
    explicit AcquisitionConverter(QObject *parent = 0);
    void setProcessAll(bool all);
    static void matDeleter(void* mat) {delete static_cast<cv::Mat*>(mat);}
    void queue(const cv::Mat & frame);
    void process(cv::Mat frame);
    void timerEvent(QTimerEvent * ev);
signals:
    void imageReady(const QImage &);
public slots:
    void processFrame(const cv::Mat & frame);
private:
    QBasicTimer m_timer;
    cv::Mat m_frame;
    bool m_processAll = true;
};

#endif // ACQUISITIONCONVERTER_H
