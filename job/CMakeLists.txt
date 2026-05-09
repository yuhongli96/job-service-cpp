add_library(job
    operatorinsert.cc
)

target_include_directories(job PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_compile_options(job PRIVATE
    -Wall -Wextra -Wpedantic
)