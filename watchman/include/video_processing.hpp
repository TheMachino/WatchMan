#ifndef VIDEO_PROCESSING_HPP
#define VIDEO_PROCESSING_HPP

#include "video_flux.hpp"
#include "opencv2/opencv.hpp"

enum processing_type
{
    No_processing,
    Color2Grey,
    EdgeDetecto,
    FaceRecognition,
    PedestrianDetection,
    ObjectDetection
};

class video_processing
{

public:
                        video_processing(cv::Mat frame);

public:
        void            NoProcessing();
        void            Color2GreyProcessing();
        cv::Mat         getFrame();

protected:
        cv::Mat         mframe;

};

#endif // VIDEO_PROCESSING_HPP
