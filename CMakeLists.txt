cmake_minimum_required(VERSION 3.16)

project(JobService LANGUAGES CXX)


message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(job)
add_subdirectory(jobqueue)
add_subdirectory(threadpool)
add_subdirectory(jobmanager)
add_subdirectory(functions)
add_subdirectory(benchmark)

add_executable(job_service main.cc)

target_include_directories(job_service PRIVATE
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(job_service PRIVATE
    functions
)
