#include "../include/show_flux.hpp"

void show_videos(std::string path_cam_config)
{

// initialization step
    video_flux video(path_cam_config);
    std::cout<<"Number of camera"<<std::endl;
    std::cout<<video.get_all_cameras().size()<<std::endl;
    char c=0;
   for (;c!=27;)
    {
        video.read_flux();
        cv::imshow("test",video.get_all_cameras()[0].get_frame());
        c=cv::waitKey(1);
    }
}
