#ifndef ACQUISITIONSENSOR_H
#define ACQUISITIONSENSOR_H
#include <opencv2/opencv.hpp>
#include <raspicam/raspicam_cv.h>
#include <raspicam/raspicam.h>
class AcquisitionSensor
{
    // cv::VideoCapture Camera;
    raspicam::RaspiCam Camera;
public:
    AcquisitionSensor();
    void startCapture();
};

#endif // ACQUISITIONSENSOR_H
