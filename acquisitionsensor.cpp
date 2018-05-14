#include "acquisitionsensor.h"
#include "opencv2/opencv.hpp"
using namespace cv;

AcquisitionSensor::AcquisitionSensor()
{
   std::cout << "Acquisition Sensor Booting";
}

void AcquisitionSensor::startCapture()
{
    std::cout << "Starting capture.";
}

