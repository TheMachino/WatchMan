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
        mcapture.push_back(cv::VideoCapture("http://" + mcamera[i].get_ipAdress()+"/video?x.mjpeg"));
    }

}

void video_flux::read_flux()
{
    cv::Size size(mcamera[0].get_size(),mcamera[0].get_size());

    for (size_t j=0;j<mcapture.size();j++)
    {
        mcapture[j] >> mframe;
        cv::resize(mframe,mframe,size);
        mcamera[j].set_frame(mframe.clone());
    }
}

std::vector<camera> video_flux::get_all_cameras()
{
    return mcamera;

}

camera video_flux::get_cam_i(int i)
{
    return mcamera[i];
}

cv::Mat video_flux::get_frame_i(int i)
{
    return mcamera[i].get_frame();
}

cv::Mat *video_flux::get_frame_i_adress(int i)
{
    return mcamera[i].get_frame_adress();
}

void video_flux::set_camera_i(camera cam, int i)
{
    mcamera[i]=cam;
}

void video_flux::set_all_cam(std::vector<camera> cam)
{
    mcamera=cam;
}

void video_flux::set_frame_cam_i(cv::Mat frame,int i)
{
    mcamera[i].set_frame(frame.clone());
}
