cmake_minimum_required(VERSION 3.15)
project(rpi-LED-HAL-cpp CXX)

# Find Boost
find_package(Boost REQUIRED)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})

# Define source files
set(SOURCE ledcontrol.h ledcontrol.cpp) 


# Enable compile commands export for tooling support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Prevent in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Use a separate build directory.")
endif()

# Require C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set warning levels
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Build the executable
add_executable(ledcontrol ${SOURCE})

# Link Boost and other necessary libraries
target_link_libraries(ledcontrol ${Boost_LIBRARIES} brainflow pigpio boost_system boost_thread ssl crypto pthread)
