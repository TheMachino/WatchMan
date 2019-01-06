#include "../include/main_run.hpp"
#include <vector>
void run(std::string path_cam_config,
              std::string path_display_config,
              std::string path_processing_config)
{
    video_flux                    video(path_cam_config);
    //Initialization of video flux
    video.read_flux();
    //end initialization of video flux
    processing_parameter          processing_parameter=video_processing::processing_config(path_processing_config);
   video_processing              processing(video.get_all_cameras()[0].get_frame()
                                             ,processing_parameter);
    std::vector<std::thread>      thread_list;
    std::mutex                    locker_thread;
    char                          stop_process=0;

    for (;stop_process!=27;)
    {

        video.read_flux();
        for(int i=0;i<video.get_all_cameras().size();i++)
        {
            processing.setFrame(video.get_all_cameras()[i].get_frame());
            locker_thread.lock();
            processing.run_process();
            locker_thread.unlock();

            video.set_frame_cam_i(processing.getFrame(),i);

        }

        show_videos(video, path_display_config);
        stop_process=cv::waitKey(1);
    }



}
