#include "../include/video_flux.hpp"


video_flux::video_flux(std::string path_to_config)
{
    initialize(path_to_config);
}

video_flux::~video_flux()
{
}

void video_flux::initialize(std::string path_to_config)
{
     mcamera=config(path_to_config);

    for(int i=0;i<static_cast<int>(mcamera.size());i++)
    {
        mcapture.push_back(cv::VideoCapture(i));
    }

}

void video_flux::read_flux()
{
    for (size_t j=0;j<mcapture.size();j++)
    {
        mcapture[j] >> mframe;
        mcamera[j].set_frame(mframe.clone());
    }
}

std::vector<camera> video_flux::get_all_cameras()
{
    return mcamera;

}
