add_library(jobmanager
    jobmanager1.cc
    jobmanager2.cc
    submit.cc
    status.cc
    result.cc
    list.cc
    stop.cc
)

target_include_directories(jobmanager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(jobmanager PUBLIC
    threadpool
)

target_compile_options(jobmanager PRIVATE
    -Wall -Wextra -Wpedantic
)