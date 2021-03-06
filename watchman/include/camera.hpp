#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <opencv2/opencv.hpp>


enum camera_type
{
    usb_cam=0,
    ip_cam
};

class camera
{
public:
                            camera();

public:
    std::string             get_camId();
    int                     get_size();
    std::string             get_cam_local();
    std::string             get_ipAdress();
    cv::Mat                 get_frame();
    cv::Mat*                get_frame_adress();
    camera_type             get_cam_type();
    void                    set_camId(std::string id);
    void                    set_cam_local(std::string local);
    void                    set_mip_adress(std::string ip_adress);
    void                    set_frame(cv::Mat frame);
    void                    set_size(int size);
    void                    set_camera_type(camera_type type_cam);

protected:
    std::string             mcam_id;
    int                     msize;
    std::string             mcam_local;
    std::string             mip_adress;
    cv::Mat                 mframe;
    camera_type             mtype;

};

#endif // CAMERA_HPP
