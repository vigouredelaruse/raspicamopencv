#include "acquisitionconverter.h"

AcquisitionConverter::AcquisitionConverter(QObject *parent) : QObject(parent)
{

}

void AcquisitionConverter::processFrame(const cv::Mat &frame)
{
    if (m_processAll) process(frame); else queue(frame);
}

void AcquisitionConverter::setProcessAll(bool all)
{
    m_processAll = all;
}

void AcquisitionConverter::queue(const cv::Mat & frame)
{
    if (!m_frame.empty()) qDebug() << "Converter dropped frame!";
    m_frame = frame;
    if (! m_timer.isActive()) m_timer.start(0, this);
}

void AcquisitionConverter::process(cv::Mat frame)
{
    cv::resize(frame, frame, cv::Size(), 0.3, 0.3, cv::INTER_AREA);
    cv::cvtColor(frame,frame,CV_BGR2RGB);

    const QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888, &matDeleter, new cv::Mat(frame) );
    Q_ASSERT(image.constBits() == frame.data);
    emit imageReady(image);
}

void AcquisitionConverter::timerEvent(QTimerEvent * ev)
{
    if (ev->timerId() != m_timer.timerId()) return;
    process(m_frame);
    m_frame.release();
    m_timer.stop();
}
