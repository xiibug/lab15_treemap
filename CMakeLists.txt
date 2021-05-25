cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME _TreeMap_) 
project(${PROJECT_NAME}) 

set(TreeMap TreeMap) 
set(main main)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TreeMap) 

add_subdirectory(gtest)
add_subdirectory(TreeMap)
add_subdirectory(main)
add_subdirectory(test)

