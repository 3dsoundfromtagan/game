#cmake_minimum_required(VERSION 3.9)
#project(SFML_test)

#set(CMAKE_CXX_STANDARD 11)

#add_executable(SFML_test main.cpp)

cmake_minimum_required(VERSION 3.2)
project(SFML_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(SFML_test ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_test ${SFML_LIBRARIES})
endif()