cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
        SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

project(server_app)
#string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
#string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
#string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

add_library(${PROJECT_NAME} STATIC
        include/NetModule.hpp
        include/actions.h
        include/board.h
        include/EventQueue.h
        include/klibriry.h
        include/object.h
        include/projectiles.h
        sources/actions.cpp
        sources/board.cpp
        sources/EventQueue.cpp
        sources/object.cpp
        sources/projectiles.cpp
        sources/NetModule.cpp
)

hunter_add_package(SFML)

find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Threads)

add_executable(serv
        main/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
  "${SFML_ROOT}/include"
  "${OPENGL_INCLUDE_DIRS}"
)

target_link_libraries(serv PUBLIC ${PROJECT_NAME} Threads::Threads ${OPENGL_LIBRARIES} sfml-graphics)
