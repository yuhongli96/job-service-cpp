add_library(threadpool
    threadpool.cc
    destructor.cc
    start.cc
    stop.cc
    workerloop.cc
    count.cc
)

target_include_directories(threadpool PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(threadpool PUBLIC
    jobqueue
)

target_compile_options(threadpool PRIVATE
    -Wall -Wextra -Wpedantic
)