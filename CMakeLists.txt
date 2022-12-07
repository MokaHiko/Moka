cmake_minimum_required(VERSION 3.0.0)

# Application Name and Platform
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
project(MokaEngine) 

# Link To Moka Engine And Client ApplicationS
add_subdirectory(./Moka) 
add_subdirectory(./TestBed) 

# Output DLLs and Executables to ${Configuration}/Bin
set_target_properties( Moka PROPERTIES RUNTIME_OUTPUT_DIRECTORY
   ${PROJECT_BINARY_DIR}/$<CONFIG>/bin )
set_target_properties( TestBed PROPERTIES RUNTIME_OUTPUT_DIRECTORY 
   ${PROJECT_BINARY_DIR}/$<CONFIG>/bin )