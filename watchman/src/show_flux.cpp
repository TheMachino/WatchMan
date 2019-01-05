#include "../include/show_flux.hpp"



display_config ReadDisplaySetting(std::string path_to_display_config)
{
    display_config screen_setting;
    tinyxml2::XMLDocument config;
    tinyxml2::XMLError error=config.LoadFile(path_to_display_config.c_str());

    if (error != tinyxml2::XML_SUCCESS) {throw "impossible to open: "+ path_to_display_config;}

    tinyxml2::XMLNode* pRoot=config.FirstChildElement("display_setting");
    if (pRoot==nullptr){throw "bad xml file";}

    tinyxml2::XMLElement* pIsOneScreen(pRoot->FirstChildElement("one_screen"));
    int state;
    pIsOneScreen->QueryIntText(&state);
    tinyxml2::XMLElement* pScreenSize(pRoot->FirstChildElement("screen_size"));
    int screen_size;
    pScreenSize->QueryIntText(&screen_size);
    screen_setting.IsOneScreen=state;
    screen_setting.size_screen=screen_size;

    return screen_setting;
}


void show_videos(video_flux video, std::string path_to_display_config)
{


    std::cout<<"Number of camera"<<std::endl;
    std::cout<<video.get_all_cameras().size()<<std::endl;
    display_config screen_setting= ReadDisplaySetting(path_to_display_config);
    if (screen_setting.IsOneScreen==0)
    {
        DisplayOneScreen(video, screen_setting.size_screen);
    }
}


void DisplayOneScreen(video_flux video, int size_screen)
{
    // initialization step
        std::cout<<"Number of camera"<<std::endl;
        std::cout<<video.get_all_cameras().size()<<std::endl;

        int size_im=video.get_all_cameras()[0].get_size();
        cv::Point corner;
        cv::Mat screen = cv::Mat::zeros(cv::Size(size_screen, size_screen), CV_64F);

        int max_im_by_line=size_screen/size_im;
        int max_i=video.get_all_cameras().size()/max_im_by_line;
        int max_j;
        //Display all flux
        for(size_t i=0; i<=static_cast<size_t>(max_i+1);i+=static_cast<size_t>(size_im))
        {
            if (i!=static_cast<size_t>(max_i))
            {
                max_j=max_im_by_line;
            }
            else
            {
                max_j=video.get_all_cameras().size()%max_im_by_line;
            }
            for(size_t j=0; j<static_cast<size_t>(max_j); j+=static_cast<size_t>(size_im))
            {
                corner.x=static_cast<int>(j);
                corner.y=static_cast<int>(i);
                (video.get_all_cameras()[max_i*i+j].get_frame()).copyTo(screen(cv::Rect(corner.x,corner.y, size_im, size_im)));
            }
        }
        cv::imshow("test",screen);
}


