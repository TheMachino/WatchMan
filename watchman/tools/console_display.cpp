#include "console_display.hpp"
#include <vector>

void put_space(int nb_total_space)
{
    for(size_t i=0; i<nb_total_space; i++)
    {
        std::cout<<" ";
    }
}

void display_param(std::vector<camera> cam)
{

    int n1=1;
    int n2=27;
    int n3=72;
    int n4=100;
    std::string cam_id;
    std::string cam_description;
    std::string cam_ip;
    std::string nb_cam= "|nb cam: " + std::to_string(cam.size());

    std::cout<<"|====================================================================================================|"<<std::endl;
    std::cout<<"|                  Running multiple usb_cam and ip_cam                                               |"<<std::endl;
    std::cout<<"|                  by Branham Mouata @TheMachino, realase 26/01/2019                                 |"<<std::endl;
    std::cout<<"|====================================================================================================|"<<std::endl;
    std::cout<<"|  camera id          ||       camera description              ||    camera ipadress/device          |"<<std::endl;
    std::cout<<"-----------------------------------------------------------------------------------------------------"<<std::endl;
    for(size_t i=0; i<cam.size();i++)
    {
    std::cout<<"|";
        put_space(n1);
        cam_id=cam[i].get_camId();
    std::cout<<cam_id;
        put_space(n2-(n1+cam_id.size()));
        cam_description=cam[i].get_cam_local();
    std::cout<<cam_description;
        put_space(n3-(n2 + cam_description.size()));
        cam_ip=cam[i].get_ipAdress();
    std::cout<<cam_ip;
        put_space(n4-(n3+ cam_ip.size()));

    std::cout<<"|"<<std::endl;

    }
    std::cout<<"-----------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<nb_cam;
    put_space(n4-nb_cam.size()+1);
    std::cout<<"|"<<std::endl;
    std::cout<<"-----------------------------------------------------------------------------------------------------"<<std::endl;


}
