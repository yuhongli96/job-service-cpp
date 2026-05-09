add_library(jobqueue
    push.cc
    pop.cc
    shutdown.cc
)

target_include_directories(jobqueue PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(jobqueue PUBLIC
    job
)

target_compile_options(jobqueue PRIVATE
    -Wall -Wextra -Wpedantic
)