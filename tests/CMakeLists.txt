cmake_minimum_required(VERSION 2.8.11)
project("TestModules")

set(SIMPLE_EXECUTABLE_NAME "SimpleTest")
set(SIMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/simple)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../engine/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../math
)

set(SIMPLE_TEST
  ${SIMPLE_DIR}/main.cpp
)


add_executable(${SIMPLE_EXECUTABLE_NAME}
  ${SIMPLE_TEST}
)


target_link_libraries(${SIMPLE_EXECUTABLE_NAME}
  ${OPENGL_GRAPHICS_ENGINE_NAME}
)