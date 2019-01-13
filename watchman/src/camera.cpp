#include "../include/camera.hpp"

camera::camera()
{
    mcam_id="";
    msize=512;
    mcam_local="";
    mip_adress="";
    mframe=cv::Scalar::all(0.0);
}

std::string camera::get_camId()
{
    return mcam_id;
}

int camera::get_size()
{
    return msize;
}

std::string camera::get_cam_local()
{
    return mcam_local;
}

std::string  camera::get_ipAdress()
{
    return mip_adress;
}

cv::Mat camera::get_frame()
{
    return mframe;
}

cv::Mat *camera::get_frame_adress()
{
    return &mframe;
}

void camera::set_camId(std::string id)
{
    mcam_id=id;
}

void camera::set_cam_local(std::string local)
{
    mcam_local=local;
}

void camera::set_mip_adress(std::string ip_adress)
{
    mip_adress=ip_adress;
}

void camera::set_frame(cv::Mat frame)
{
    mframe=frame;
}

void camera::set_size(int size)
{
    msize=size;
}
