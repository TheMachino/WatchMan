cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(EXECUTABLE_OUTPUT_PATH /home/branham/WatchMan/watchman/bin)
project(watchman)
find_package(OpenCV REQUIRED)
add_executable(${PROJECT_NAME} "src/main.cpp" "src/video_flux.cpp"
                                "src/camera.cpp" "src/load_config.cpp"
                                "src/show_flux.cpp"
                                "src/main_run.cpp"
                                "src/video_processing.cpp"
                                )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} tinyxml2)
