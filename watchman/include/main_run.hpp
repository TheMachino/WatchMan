#ifndef MAIN_RUN_HPP
#define MAIN_RUN_HPP

#include <string>
#include "video_flux.hpp"
#include "video_processing.hpp"
#include "show_flux.hpp"
#include <thread>
#include <mutex>

void run(std::string path_cam_config,
              std::string path_display_config,
              std::string path_processing_config);
#endif // MAIN_RUN_HPP
