cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# Add include paths
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/vendor/glad
    ${PROJECT_SOURCE_DIR}/vendor/GLFW/include
    ${PROJECT_SOURCE_DIR}/vendor/glad/include
)

# Gather all source files
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    vendor/glad.c
)

# Create the main executable
add_executable(LearnOpenGL ${SRC_FILES})

add_subdirectory(vendor)
add_subdirectory(src)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()

# Link system libs
find_package(OpenGL REQUIRED)
target_link_libraries(LearnOpenGL
    ${OPENGL_gl_LIBRARY}
    glfw
    dl
)
