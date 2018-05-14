#include "simpleraspicamtest.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include "consolecapture.h"
#include "consoleviewer.h"
#include "acquisitionsensor.h"
#include "acquisitionconverter.h"

// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt
Q_DECLARE_METATYPE(cv::Mat)
int main(int argc, char *argv[])
{

    qRegisterMetaType<cv::Mat>();
    QApplication a(argc, argv);

    SimpleRaspiCamTest w;
    w.show();
/*
    ConsoleViewer* view = new ConsoleViewer(a, QPoint(20,20), QSize(320,240));
    ConsoleCapture capture;
    AcquisitionConverter converter;
    QThread captureThread, converterThread;

    // setup the threads
    converter.setProcessAll(false);
    captureThread.start();
    converterThread.start();
    capture.moveToThread(&captureThread);
    converter.moveToThread(&converterThread);

    // wire sluts
    QObject::connect(&capture, &ConsoleCapture::matReady, &converter, &AcquisitionConverter::processFrame);
    QObject::connect(&converter, &AcquisitionConverter::imageReady, &view, &ConsoleViewer::setImage);

    view.show();

    QObject::connect(&capture, &ConsoleCapture::started, []() {qDebug() << "capture started.";});
    QMetaObject::invokeMethod(&capture, "start");
*/

    return a.exec();
}
