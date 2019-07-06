
cmake_minimum_required(VERSION 3.0)
project(PoliceVR)

# Have CMake find our pthreads library within our toolchain (required for this library)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

#Bring the headers, such as Student.h into the project
include_directories(SHARED include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

add_executable(PoliceVR ${SOURCES})

# Make sure the executable links to the wiringPi lib
target_link_libraries(PoliceVR wiringPi)
target_link_libraries(PoliceVR pthread)

