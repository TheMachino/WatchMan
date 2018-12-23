#include "../include/camera.hpp"

camera::camera()
{
    mcam_id=0;
    msize=512;
    mcam_local="";
    mip_adress=0u;
    mframe=cv::Scalar::all(0.0);
}
