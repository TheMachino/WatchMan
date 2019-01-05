#include "../include/video_processing.hpp"

video_processing::video_processing(cv::Mat frame)
{
    mframe=frame;
}

void video_processing::NoProcessing()
{
    //No treatment;
}

void video_processing::Color2GreyProcessing()
{
    cv::cvtColor(mframe, mframe, cv::COLOR_BGR2GRAY);
}

cv::Mat video_processing::getFrame()
{
   return mframe;
}
