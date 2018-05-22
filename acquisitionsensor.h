#ifndef ACQUISITIONSENSOR_H
#define ACQUISITIONSENSOR_H
#include <opencv2/opencv.hpp>
#ifdef __linux__
#include <raspicam/raspicam_cv.h>
#include <raspicam/raspicam.h>
#endif

class AcquisitionSensor
{
#ifdef __APPLE_CC__
    cv::VideoCapture Camera;
#elif __linux__
    raspicam::RaspiCam Camera;
#endif
public:
    AcquisitionSensor();
    void startCapture();
};

#endif // ACQUISITIONSENSOR_H
