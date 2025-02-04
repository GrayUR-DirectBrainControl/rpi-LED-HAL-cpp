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
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -pedantic -Werror)  # Enable warnings for GCC/Clang
endif()


# Detect Platform (PC vs Raspberry Pi) 
if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm" OR CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    set(TARGET_PLATFORM "RaspberryPi")
else()
    set(TARGET_PLATFORM "DevelopmentPC")
endif()

# Build Executable
add_executable(ledcontrol ${SOURCE})

# Link pigpio and pthread only on Raspberry Pi
if(TARGET_PLATFORM STREQUAL "RaspberryPi")
    target_link_libraries(ledcontrol pigpio pthread)
endif()

