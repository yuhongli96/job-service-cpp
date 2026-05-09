add_executable(job_benchmark
    benchmark.cc
)

target_link_libraries(job_benchmark PRIVATE
    functions
)

target_include_directories(job_benchmark PRIVATE
    ${CMAKE_SOURCE_DIR}
)

target_compile_options(job_benchmark PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)