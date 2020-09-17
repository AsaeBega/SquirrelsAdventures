cmake_minimum_required (VERSION 3.6)
project (SquirrelsAddventures)

add_executable(SquirrelsAdventures Source.cpp)

add_subdirectory (API/sleepy-discord)
target_link_libraries (SquirrelsAdventures sleepy-discord)