#ifndef VIDEO_PROCESSING_HPP
#define VIDEO_PROCESSING_HPP

#include "video_flux.hpp"
#include "opencv2/opencv.hpp"
#include <tinyxml2.h>


enum processing_type
{
    No_processing=0,
    Color2Grey,
    EdgeDetecto,
    FaceRecognition,
    PedestrianDetection,
    ObjectDetection
};

struct processing_parameter
{
    processing_type ToDo;
    std::string     path2parameter;
};

class video_processing
{

public:
                                        video_processing(cv::Mat frame, processing_parameter process_param);
                                        video_processing();

public:
        void                            NoProcessing(cv::Mat* frame);
        void                            Color2GreyProcessing(cv::Mat* frame);
        cv::Mat                         getFrame();
        void                            setFrame(cv::Mat frame);
        void                            run_process(video_flux video);

public:
        static processing_parameter     processing_config(std::string path_processing_config);

protected:
        cv::Mat                         mframe;
        processing_parameter            mprocessing_parameter;

};

#endif // VIDEO_PROCESSING_HPP
