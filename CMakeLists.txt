cmake_minimum_required(VERSION 3.0.2)
project(qpoasesExample)

find_package(Eigen3 REQUIRED)

include_directories(include)
include_directories( include/qpOASES )
include_directories( include/qpOASES/extras )

link_directories( ${PROJECT_SOURCE_DIR}/lib )

add_executable( ${PROJECT_NAME} src/example1.cpp)

target_link_libraries( ${PROJECT_NAME} qpOASES Eigen3::Eigen)
