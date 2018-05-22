#include "consolecapture.h"
ConsoleCapture::ConsoleCapture(QObject *parent) : QObject(parent)
{

}


void ConsoleCapture::start(){
    qDebug() << "ConsoleCapture starting";
    if(!m_videoCapture){
#ifdef  __APPLE_CC__
        m_videoCapture.reset(new cv::VideoCapture(0));
#elif __linux__
        m_videoCapture.reset(new raspicam::RaspiCam_Cv());
        m_videoCapture->open();
#endif

        //m_videoCapture.reset(cam);
        qDebug() << "reset RaspiCam_CV";
    }

    if(m_videoCapture->isOpened()){
        qDebug() << "ConsoleCapture started successfully: starting timer";
        m_timer.start(0,this);
        emit started();
    }
    else{
        qDebug() << "failed to start camera capture";
    }
}

void ConsoleCapture::stop(){
    qDebug() << "XconsoleCaptur stopping";
    m_timer.stop();
}


void ConsoleCapture::timerEvent(QTimerEvent *ev){
    if(ev->timerId() != m_timer.timerId()) return;
    cv::Mat frame;

    if(!m_videoCapture->grab()){
        m_timer.stop();
        qDebug() << "framegrab failed: timerEvent";
        return;
    }


    m_videoCapture->retrieve(frame);
    // qDebug() << "retrieved frame: signalling listeners";
    // signal frame reaady to listeners
    emit matReady(frame);
}
