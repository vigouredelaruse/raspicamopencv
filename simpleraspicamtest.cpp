#include "simpleraspicamtest.h"
#include "ui_simpleraspicamtest.h"
#include <opencv2/opencv.hpp>
#include "consolecapture.h"
#include "consoleviewer.h"
#include "acquisitionsensor.h"
#include "acquisitionconverter.h"

// overrides
void SimpleRaspiCamTest::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "SimpleRaspicamTest",
                                                               tr("Ready To Exit?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    if(resBtn != QMessageBox::Yes){
        event->ignore();
    } else{
        event->accept();
    }
}

// underrides
SimpleRaspiCamTest::SimpleRaspiCamTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleRaspiCamTest)
{
    ui->setupUi(this);

    // initialize the acquisition sensor
    //AcquisitionSensor sensor;
    sensor.startCapture();


    // ConsoleViewer* view = new ConsoleViewer(this, QPoint(20,20), QSize(320,240));
    // view = new ConsoleViewer(this, QPoint(20,20), QSize(320,240));
    //ConsoleCapture capture;
    //AcquisitionConverter converter;
    // QThread captureThread, converterThread;
    capture.moveToThread(&captureThread);
    converter.moveToThread(&converterThread);
    // setup the threads
    converter.setProcessAll(false);

    qDebug() << "start converter and capture threads";
    captureThread.start();
    qDebug() << "capture thread started.";
    converterThread.start();
    qDebug() << "converter thread started.";
    /*
    capture.moveToThread(&captureThread);
    converter.moveToThread(&converterThread);
    */

    // wire sluts
    QObject::connect(&capture, &ConsoleCapture::matReady, &converter, &AcquisitionConverter::processFrame);
    QObject::connect(&converter, &AcquisitionConverter::imageReady, ui->consoleViewer, &ConsoleViewer::setImage);
    qDebug() << "wired sluts.";
    //view.show();

    QObject::connect(&capture, &ConsoleCapture::started, []() {qDebug() << "capture started.";});
    QMetaObject::invokeMethod(&capture, "start");


}

SimpleRaspiCamTest::~SimpleRaspiCamTest()
{
    delete ui;
}
