cmake_minimum_required(VERSION 3.20)
project(SDL2_Engine_Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Use Ninja if available
if(NOT CMAKE_GENERATOR)
    set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "")
endif()

set(SYSTEM_TARGET "" CACHE STRING "Choose target system: Windows, Linux, Emscripten")
if(NOT SYSTEM_TARGET)
    message(FATAL_ERROR "Please set -DSYSTEM_TARGET=<Windows|Linux|Emscripten>")
endif()

set(BASE_DIR ${CMAKE_SOURCE_DIR}/..)
set(SOURCE_DIR ${BASE_DIR}/Source)
set(DEPENDENCIES_DIR ${BASE_DIR}/Dependencies)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASE_DIR}/Bin/${SYSTEM_TARGET})

file(GLOB_RECURSE SYSTEM_SRC CONFIGURE_DEPENDS
    ${SOURCE_DIR}/System/*.cpp
    ${SOURCE_DIR}/System/*.h
)

file(GLOB_RECURSE APP_SRC CONFIGURE_DEPENDS
    ${SOURCE_DIR}/Application/*.cpp
    ${SOURCE_DIR}/Application/*.h
)

# System (static lib)
add_library(System STATIC ${SYSTEM_SRC})

target_include_directories(System PUBLIC
    ${DEPENDENCIES_DIR}/imgui-master
    ${DEPENDENCIES_DIR}/imgui-master/backends
    ${SOURCE_DIR}
    ${SOURCE_DIR}/System
)

target_precompile_headers(System PRIVATE ${SOURCE_DIR}/System/stdafx.h)

# Application (exe)
add_executable(Application ${APP_SRC})

target_include_directories(Application PRIVATE
    ${SOURCE_DIR}
    ${SOURCE_DIR}/System
    ${SOURCE_DIR}/Application
)

target_link_libraries(Application PRIVATE System)

target_precompile_headers(Application PRIVATE ${SOURCE_DIR}/Application/stdafx.h)

# Platform-specific includes and links
if(SYSTEM_TARGET STREQUAL "Linux")
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(SDL2 REQUIRED sdl2)
    pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
    pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
    pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

    target_include_directories(System PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS}
    )

    target_link_libraries(System PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
    )

    target_compile_definitions(System PRIVATE __linux__ LINUX _LINUX)
    target_compile_definitions(Application PRIVATE __linux__ LINUX _LINUX)

elseif(SYSTEM_TARGET STREQUAL "Windows")
    target_include_directories(System PRIVATE
        ${DEPENDENCIES_DIR}/SDL2/SDL2/include
        ${DEPENDENCIES_DIR}/SDL2/SDL2_image/include
        ${DEPENDENCIES_DIR}/SDL2/SDL2_ttf/include
        ${DEPENDENCIES_DIR}/SDL2/SDL2_mixer/include
    )

    target_link_directories(System PRIVATE
        ${DEPENDENCIES_DIR}/SDL2/SDL2/lib/x64
        ${DEPENDENCIES_DIR}/SDL2/SDL2_image/lib/x64
        ${DEPENDENCIES_DIR}/SDL2/SDL2_ttf/lib/x64
        ${DEPENDENCIES_DIR}/SDL2/SDL2_mixer/lib/x64
    )

    target_link_libraries(System PRIVATE
        ${DEPENDENCIES_DIR}/SDL2/SDL2/lib/x64/SDL2.lib
        ${DEPENDENCIES_DIR}/SDL2/SDL2_image/lib/x64/SDL2_image.lib
        ${DEPENDENCIES_DIR}/SDL2/SDL2_ttf/lib/x64/SDL2_ttf.lib
        ${DEPENDENCIES_DIR}/SDL2/SDL2_mixer/lib/x64/SDL2_mixer.lib
    )

    target_compile_definitions(System PRIVATE WIN32 WIN64 _WIN32 _WIN64 _WINDOWS WINDOWS)
    target_compile_definitions(Application PRIVATE WIN32 WIN64 _WIN32 _WIN64 _WINDOWS WINDOWS)

    set_target_properties(Application PROPERTIES
        LINK_FLAGS_DISTRIBUTION "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS"
    )

endif()

# Configuration-specific defines
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Distribution" CACHE STRING "" FORCE)

target_compile_options(System PRIVATE
    "$<$<CONFIG:Debug>:-g>"
    "$<$<CONFIG:Debug>:-O0>"
    "$<$<CONFIG:Release>:-g>"
    "$<$<CONFIG:Release>:-O2>"
    "$<$<CONFIG:Distribution>:-O3>"
)

target_compile_definitions(System PRIVATE
    "$<$<CONFIG:Debug>:DEBUG;_DEBUG>"
    "$<$<CONFIG:Release>:RELEASE;_RELEASE;_NDEBUG>"
    "$<$<CONFIG:Distribution>:DISTRIBUTION;_DISTRIBUTION>"
)

target_compile_options(Application PRIVATE
    "$<$<CONFIG:Debug>:-g>"
    "$<$<CONFIG:Debug>:-O0>"
    "$<$<CONFIG:Release>:-g>"
    "$<$<CONFIG:Release>:-O2>"
    "$<$<CONFIG:Distribution>:-O3>"
)

target_compile_definitions(Application PRIVATE
    "$<$<CONFIG:Debug>:DEBUG;_DEBUG>"
    "$<$<CONFIG:Release>:RELEASE;_RELEASE;_NDEBUG>"
    "$<$<CONFIG:Distribution>:DISTRIBUTION;_DISTRIBUTION>"
)