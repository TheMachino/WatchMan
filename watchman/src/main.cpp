#include <iostream>
#include "../include/load_config.hpp"
using namespace std;

int main(int argc, char** argv)
{
    std::string path("");
    if(argc>1){path=argv[1];}
    vector<camera*> cam_vec= config(argv[1]);
    cout<<"Reading config"<<endl;
    cout << path<< endl;
    cout<<"Number of cam"<<endl;
    cout<<cam_vec.size()<<endl;
    for(size_t i=0;i<cam_vec.size();i++)
    {
        cout<<"*********************"<<endl;
        cout<<cam_vec[i]->get_camId()<<endl;
        cout<<cam_vec[i]->get_cam_local()<<endl;
        cout<<cam_vec[i]->get_ipAdress()<<endl;

    }

    for(size_t i=0;i<cam_vec.size();i++)
    {
        cout<<"*********************"<<endl;
        delete cam_vec[i];

    }
    return 0;
}
