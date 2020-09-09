cmake_minimum_required(VERSION 3.10)
project(foro VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

set(conmenu_include
    include/conmenu/menu.hpp
    include/conmenu/opcion.hpp
)

set(src_include
    ${conmenu_include}
)

set(src_menu
    menu/menu.cpp
)

set(src
    ${src_include}
    ${src_menu}
    src/source.cpp
)


#add_executable(foro ${src})
add_executable(source ${src} src/source.cpp)
target_include_directories(source PRIVATE include)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
