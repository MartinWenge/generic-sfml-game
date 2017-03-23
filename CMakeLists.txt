cmake_minimum_required (VERSION 2.6)

project(SNAKE)

#set(CMAKE_VERBOSE_MAKEFILE ON)

#include_directories("./")
#include_directories("./core")

include_directories("/usr/include/SFML/")
include_directories("./include")
include_directories("./")

#include_directories("/usr/include/SFML/include")
#directoriy for fonts:
#include_directories("/usr/share/fonts/truetype/freefont")

add_subdirectory("./src")

# Define sources and executable
file(GLOB SOURCES
    src/*.cpp
)
set(CLASS_LIST "src/Game.cpp" "src/PauseScreen.cpp" "src/SplashScreen.cpp" "src/MainMenu.cpp" ) # "src/Button.cpp")

#add_executable(${EXECUTABLE_NAME} ${SOURCES})

set(EXECUTABLE_NAME "genericGame.exe")
add_executable( ${EXECUTABLE_NAME} main.cpp ${CLASS_LIST} ) #${SOURCES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

