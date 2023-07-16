cmake_minimum_required(VERSION 3.0.2)
project(qpoasesExample)

find_package(Eigen3 REQUIRED)

find_library(LIBQPOASES qpOASES lib)
include_directories(include)


add_executable( ${PROJECT_NAME} src/example1.cpp)

target_link_libraries( ${PROJECT_NAME} ${LIBQPOASES} Eigen3::Eigen)