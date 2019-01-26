#include "../include/video_processing.hpp"
#include <thread>
#include <mutex>

video_processing::video_processing(cv::Mat frame, processing_parameter process_param)
{
    mframe=frame;
    mprocessing_parameter=process_param;
}

video_processing::video_processing()
{
    mframe=cv::Mat::zeros(512,512,CV_64F);
    mprocessing_parameter.ToDo=No_processing;
    mprocessing_parameter.path2parameter="";
}

void video_processing::NoProcessing(video_flux* video, int i)
{
    //No treatment;
}

void video_processing::Color2GreyProcessing(video_flux* video,int i)
{
    cv::Mat frame;
    cv::cvtColor(video->get_frame_i(i), frame, cv::COLOR_BGR2GRAY);
    video->set_frame_cam_i(frame, i);

}

cv::Mat video_processing::getFrame()
{
    return mframe.clone();
}

void video_processing::setFrame(cv::Mat frame)
{
    mframe=frame.clone();
}

void video_processing::run_process(video_flux*  video)
{
    std::vector<std::thread> all_thread;
    std::mutex               locker_thread;

    if(mprocessing_parameter.ToDo==No_processing)
    {
            for(int i=0;i<video->get_all_cameras().size();i++)
            {

               locker_thread.lock();
               all_thread.push_back(std::thread(&video_processing::NoProcessing,
                                                this,
                                                video, i)
                                    );

               locker_thread.unlock();
            }
    }
    else if(mprocessing_parameter.ToDo==Color2Grey)
    {

        for(int i=0;i<video->get_all_cameras().size();i++)
        {
          all_thread.push_back(std::thread(&video_processing::Color2GreyProcessing,
                                            this,
                                            video, i)
                                );

        }


    }
    else
    {
        for(int i=0;i<video->get_all_cameras().size();i++)
        {
           all_thread.push_back(std::thread(&video_processing::NoProcessing,
                                            this,
                                            video, i)
                                );

        }

    }

    for(int i=0;i<video->get_all_cameras().size();i++)
    {
        all_thread[i].join();
    }

    all_thread.clear();

}

processing_parameter video_processing::processing_config(std::string path_processing_config)
{
    tinyxml2::XMLDocument config;
    processing_parameter  processing_config;
    tinyxml2::XMLError error=config.LoadFile(path_processing_config.c_str());

    if (error != tinyxml2::XML_SUCCESS) {std::cout<< "impossible to open: "<<std::endl;}

    tinyxml2::XMLNode* pRoot=config.FirstChildElement("config_processing");
    if (pRoot==nullptr){throw "bad xml file";}

    tinyxml2::XMLElement* pProcessing_type(pRoot->FirstChildElement("processing_type"));
    int processing;
    pProcessing_type->QueryIntText(&processing);
    tinyxml2::XMLElement* pPath2Config(pRoot->FirstChildElement("path_config_processing"));
    std::string path2config=pPath2Config->GetText();

    processing_config.ToDo=static_cast<processing_type>(processing);
    processing_config.path2parameter=path2config;

    return processing_config;
}
