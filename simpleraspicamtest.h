#ifndef SIMPLERASPICAMTEST_H
#define SIMPLERASPICAMTEST_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "consolecapture.h"
#include "consoleviewer.h"
#include "acquisitionsensor.h"
#include "acquisitionconverter.h"
namespace Ui {
class SimpleRaspiCamTest;
}

class SimpleRaspiCamTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimpleRaspiCamTest(QWidget *parent = 0);
    ~SimpleRaspiCamTest();

private:
    Ui::SimpleRaspiCamTest *ui;
    ConsoleCapture capture;
    AcquisitionSensor sensor;
    AcquisitionConverter converter;
    ConsoleViewer* view;
    QThread captureThread, converterThread;

    void closeEvent(QCloseEvent *event);
};

#endif // SIMPLERASPICAMTEST_H
