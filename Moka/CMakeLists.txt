cmake_minimum_required(VERSION 3.0.0)

# Application Name and Platform
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
project(Moka VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB HEADERS 
	"src/Core/*.h"
	"src/*.h")
file(GLOB SOURCES
	"src/Core/*.cpp"
	"src/*.cpp")
add_library(Moka SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "./src")
target_compile_definitions(${PROJECT_NAME} PRIVATE MEXPORT)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
