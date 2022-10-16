# CMake minimum version
cmake_minimum_required(VERSION 3.16)


# project inforrmation
project(project2)

# search the source files in the src directory 
# and store them into the variable DIR_SRCS
aux_source_directory(./src DIR_SRCS)

# add the directory of include
include_directories(include)

# specify the build target
add_executable(project2 ${DIR_SRCS})


# target_link_libraries(project2 ${CMAKE_THREAD_LIBS_INIT})

