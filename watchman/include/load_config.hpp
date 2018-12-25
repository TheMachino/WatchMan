#ifndef LOAD_CONFIG_HPP
#define LOAD_CONFIG_HPP

#include <tinyxml2.h>
#include <vector>
#include <string>
#include <memory>
#include "camera.hpp"

std::vector<camera*> config(std::string path_to_config);
#endif // LOAD_CONFIG_HPP
