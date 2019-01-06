#ifndef VIDEO_FLUX_HPP
#define VIDEO_FLUX_HPP

#include <vector>
#include <memory>
#include "opencv2/opencv.hpp"
#include "camera.hpp"
#include <string>
#include "load_config.hpp"
class video_flux
{
public:
    /**
     * @brief video_flux
     * @param path_to_config path to the camera config file
     */
                                                video_flux(std::string path_to_config);

public:
    virtual                                     ~video_flux();
public:
    /**
     * @brief initialize initializes the attributs according to the camera config file
     * @param path_to_config path to the camera config file
     */
    void                                        initialize(std::string path_to_config);
    /**
     * @brief read_flux reads all camera flux according to the config file
     */
    void                                        read_flux();
    std::vector<camera>                         get_all_cameras();
    void                                        set_camera_i(camera cam, int i);
    void                                        set_all_cam(std::vector<camera> cam);
    void                                        set_frame_cam_i(cv::Mat frame, int i);

protected:
    std::vector<cv::VideoCapture>               mcapture;
    cv::Mat                                     mframe;
    std::vector<camera>                         mcamera;
};

#endif // VIDEO_FLUX_HPP
