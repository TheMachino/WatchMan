#ifndef SHOW_FLUX_HPP
#define SHOW_FLUX_HPP

#include <vector>
#include <string>
#include <iostream>
#include <tinyxml2.h>
#include "load_config.hpp"
#include "camera.hpp"
#include "video_flux.hpp"
#include "../data_struct/data_structure.hpp"
/**
 * @brief show_videos show all videos flux before/after processsing
 * @param all_flux before/After processing
 */
void show_videos(video_flux video, std::string path_to_display_config);
/**
 * @brief ReadDisplaySetting read the param screen display and return
 * configuration as a structure
 * @param path_to_display_config path to the display config
 * @return display_config struct
 */
display_config ReadDisplaySetting(std::string path_to_display_config);

/**
 * @brief DisplayOneScreen displays all cam in one screen
 * @param path_cam_config path to camera config
 */
void DisplayOneScreen(video_flux video, int size_screen);

#endif // SHOW_FLUX_HPP

