#ifndef READ_FLUX_HPP
#define READ_FLUX_HPP

#include <tinyxml2.h>
#include <opencv2/opencv.hpp>
#include <vector>

std::vector<cv::Mat> read_flux(std::string path_to_cam_config);

#endif // READ_FLUX_HPP
