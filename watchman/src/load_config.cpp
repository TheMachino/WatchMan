#include "../include/load_config.hpp"

std::vector<camera*> config(std::string path_to_config)
{
    std::vector<camera*> cam_vec;
    tinyxml2::XMLDocument config;
    tinyxml2::XMLError error=config.LoadFile(path_to_config.c_str());

    if (error != tinyxml2::XML_SUCCESS) {throw "impossible to open: "+ path_to_config;}

    tinyxml2::XMLNode* pRoot=config.FirstChildElement("cam_setting");
    if (pRoot==nullptr){throw "bad xml file";}

    tinyxml2::XMLElement* pImages_size(pRoot->FirstChildElement("images_size"));
    int images_size;
    pImages_size->QueryIntText(&images_size);

    tinyxml2::XMLElement* pNumberCam(pRoot->FirstChildElement("nb_cam"));
    int nbCam;
    pNumberCam->QueryIntText(&nbCam);

    tinyxml2::XMLElement* pCamDescriptors;
    tinyxml2::XMLElement* pCamDescriptorsChild;
    std::string c_num_cam;
    std::string c_cam_id;
    std::string c_cam_local;
    std::string c_cam_ipAdress;

    std::string num_cam;
    std::string cam_id;
    std::string cam_local;
    unsigned int cam_ipAdress;

    for(size_t i=0; i<static_cast<size_t>(nbCam);i++)
    {
        cam_vec.push_back(new camera);
        c_num_cam=std::string("cam")+std::to_string(i+1);
        c_cam_id=c_num_cam+std::string("_id");
        c_cam_local=c_num_cam+std::string("_local");
        c_cam_ipAdress=c_num_cam+std::string("_ipAdress");

        pCamDescriptors=pRoot->FirstChildElement(c_num_cam.c_str());
        pCamDescriptorsChild=pCamDescriptors->FirstChildElement(c_cam_id.c_str());
        cam_vec[i]->set_camId(pCamDescriptorsChild->GetText());

        pCamDescriptorsChild=pCamDescriptors->FirstChildElement(c_cam_local.c_str());
        cam_vec[i]->set_cam_local(pCamDescriptorsChild->GetText());

        pCamDescriptorsChild=pCamDescriptors->FirstChildElement(c_cam_ipAdress.c_str());
        pCamDescriptorsChild->QueryUnsignedText(&cam_ipAdress);
        cam_vec[i]->set_mip_adress(cam_ipAdress);
        cam_vec[i]->set_size(images_size);

    }



    return cam_vec;

}
