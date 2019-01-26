#include <iostream>
#include "../include/load_config.hpp"
#include "../include/show_flux.hpp"
#include "../include/main_run.hpp"
using namespace std;

int main(int argc, char** argv)
{
    system ("clear");
    string path_cam_config=argv[1];
    string path_display_config=argv[2];
    string path_processing_config=argv[3];

    run(path_cam_config, path_display_config, path_processing_config);

    return 0;
}
