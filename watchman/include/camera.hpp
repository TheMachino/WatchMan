#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <string>
#include <opencv2/opencv.hpp>

class camera
{
public:
                    camera();

public:
    int             get_camId();
    int             get_size();
    std::string     get_cam_local();
    unsigned int    get_ipAdress();
    void            set_camId(int id);
    void            set_cam_local(std::string local);
    void            set_mip_adress(unsigned int ip_adress);
    void            set_frame(cv::Mat frame);
    void            set_size(int size);

protected:
    int              mcam_id;
    int              msize;
    std::string      mcam_local;
    unsigned int     mip_adress;
    cv::Mat          mframe;
};

#endif // CAMERA_HPP
