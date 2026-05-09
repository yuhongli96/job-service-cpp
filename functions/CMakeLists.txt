add_library(functions
    isnumber.cc
    list.cc
    showmenu.cc
    showresult.cc
    showstatus.cc
    submitjob.cc
    defaultworkercount.cc
)

target_include_directories(functions PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(functions PUBLIC
    jobmanager
)

target_compile_options(functions PRIVATE
    -Wall -Wextra -Wpedantic
)