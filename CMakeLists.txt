cmake_minimum_required(VERSION 3.5.0)
project(DLS VERSION 0.1.0 LANGUAGES C CXX)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(DLS main.cpp)
target_include_directories(DLS PRIVATE include)
target_include_directories(DLS PRIVATE lib)
target_include_directories(DLS PRIVATE lib/cereal-1.3.2/include)

target_sources(DLS PRIVATE src/game.cpp)
target_sources(DLS PRIVATE src/types/core/window.cpp)

target_link_libraries(DLS OpenGL::GL)

# if(MSVC)
#   target_compile_options(DLS PRIVATE /W4 /WX)
# else()
#   target_compile_options(DLS PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif()

include(CTest)
enable_testing()
