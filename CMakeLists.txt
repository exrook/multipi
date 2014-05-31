cmake_minimum_required(VERSION 2.8)

set(MULTIPI_SOURCES main.c pi.c)
set(COMPUTE_SOURCES compute.c pi.c)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
project(multipi C)

add_custom_target(cclean git clean -Xdf)

find_package(OpenMP REQUIRED)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
find_package(GMP REQUIRED)

add_executable(multipi ${MULTIPI_SOURCES})
add_executable(compute ${COMPUTE_SOURCES})
include_directories(${GMP_INCLUDE_DIRS})
target_link_libraries (multipi ${GMP_LIBRARIES})
target_link_libraries (compute ${GMP_LIBRARIES})

install(FILES pi.h DESTINATION include)
install(TARGETS multipi RUNTIME DESTINATION bin)
