cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(wrp CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

if (CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-Wall -g -O0)
else()
	add_definitions(-Wall -O3)
endif()

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

include_directories("${WRP_ROOT}/src/include/")


# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

include(cmake/googletest.cmake)
fetch_googletest(
	${PROJECT_SOURCE_DIR}/cmake
	${PROJECT_BINARY_DIR}/googletest
	)

enable_testing()
add_subdirectory(test)
