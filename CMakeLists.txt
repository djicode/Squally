# Copyright 2019 Squalr
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(Squally VERSION 1.1.5 LANGUAGES C CXX)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Enable if we ever decide to use IWYU
# find_program(IWYU_PATH NAMES include-what-you-use iwyu)
# if(IWYU_PATH)
    # set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${IWYU_PATH})
    # set(CMAKE_C_INCLUDE_WHAT_YOU_USE ${IWYU_PATH})
# endif()

# External dependencies
find_package(tinyxml2 REQUIRED)
find_package(SteamWorks REQUIRED)

if(UNIX)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenSSL REQUIRED)
endif()

###############################################################################
# Dependency Fixing
###############################################################################

# Fix tinyxml2 relwithdebinfo configuration (chooses debug instead of release
# for relwithdebinfo)
set_target_properties(tinyxml2::tinyxml2 PROPERTIES
    MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE
)

###############################################################################
###############################################################################

# Bundled Dependencies
add_subdirectory(${PROJECT_SOURCE_DIR}/cocos2d)
add_subdirectory(${PROJECT_SOURCE_DIR}/external)

# Capture configuration to header
configure_file(
    ${PROJECT_SOURCE_DIR}/Source/Config.h.in 
    ${CMAKE_BINARY_DIR}/Generated/Config.h
)

# Sources
add_subdirectory(${PROJECT_SOURCE_DIR}/Source)
add_subdirectory(${PROJECT_SOURCE_DIR}/Launcher)
