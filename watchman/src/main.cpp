#include <iostream>
#include "../include/load_config.hpp"
#include "../include/show_flux.hpp"
using namespace std;

int main(int argc, char** argv)
{
    std::string path("");
    std::vector<camera> cam;
    if(argc>1){path=argv[1];}
    cam=config(path);
    //video_flux video(path);
    show_videos(path);
    cout<<"path to config file"<<endl;
    cout<<path<<endl;
    cout<<"number of cameras :"<<cam.size()<<endl;

    /*for(size_t i=0;i<cam.size();i++)
    {
        cout<<"cam id: "<<cam[i].get_camId()<<endl;
        cout<<"cam location: "<<cam[i].get_cam_local()<<endl;
        cout<<"cam ip adress: "<<cam[i].get_ipAdress()<<endl;
        cout<<"cam size: "<<cam[i].get_size()<<endl;
    }*/

    return 0;
}
