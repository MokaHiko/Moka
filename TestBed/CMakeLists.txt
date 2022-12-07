cmake_minimum_required(VERSION 3.0.0)

# Application Name and Platform
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
project(TestBed VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Moka)

# Logger debug definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
	MASSERTIONS_ENABLED
	LOG_INFO_ENABLED
	LOG_DEBUG_ENABLED
	LOG_WARN_ENABLED
	)