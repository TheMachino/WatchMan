#include "../include/video_flux.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <random>

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
     cv::Mat frame;
     int cam_usb_num;
    for(int i=0;i<static_cast<int>(mcamera.size());i++)
    {
        if(mcamera[i].get_cam_type()==camera_type::ip_cam)
        {
            mcapture.push_back(cv::VideoCapture("http://" + mcamera[i].get_ipAdress()+"/video?x.mjpeg"));

        }

        else
        {
            cam_usb_num=std::stoi(mcamera[i].get_ipAdress());
            mcapture.push_back(cv::VideoCapture(cam_usb_num));
        }


        mframe.push_back(frame.clone());

    }


}

void video_flux::read_flux()
{
    cv::Size size(mcamera[0].get_size(),mcamera[0].get_size());

    for (size_t j=0;j<mcapture.size();j++)
    {
        mcapture[j] >> mframe[j];
        cv::resize(mframe[j],mframe[j],size);
        mcamera[j].set_frame(mframe[j].clone());
    }
}

void video_flux::read_one_flux(int i)
{
    cv::Size size(mcamera[0].get_size(),mcamera[0].get_size());

    if(!mcapture[i].isOpened())
    {
        mframe[i]=noiseFrame(size, CV_8UC3).clone();
    }
    else
    {
        mcapture[i] >> mframe[i];

    }
    cv::resize(mframe[i],mframe[i],size);
    mcamera[i].set_frame(mframe[i].clone());
}

void video_flux::read_flux_multithread()
{
    std::vector<std::thread> all_thread;
    std::mutex               locker_thread;

    for (int i=0;i<mcapture.size();i++)
    {
        locker_thread.lock();
        all_thread.push_back(std::thread(&video_flux::read_one_flux, this,i));
        locker_thread.unlock();
    }

    for(int j=0;j<all_thread.size();j++)
    {
        all_thread[j].join();
    }

    all_thread.clear();
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

cv::Mat video_flux::noiseFrame(cv::Size size, int type)
{
    cv::Mat frame(size, type);
    cv::MatIterator_<cv::Vec3b> it, end;
    for( it = frame.begin<cv::Vec3b>(), end = frame.end<cv::Vec3b>(); it != end; ++it)
    {
        (*it)[0] = 0;
        (*it)[1] = 200;
        (*it)[2] = 0;
    }
   return frame;
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
    mcamera[i].set_frame(frame);
}
