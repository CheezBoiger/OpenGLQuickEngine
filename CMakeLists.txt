cmake_minimum_required(VERSION 2.8.11)
project ("OpenGLGraphicsEngine")


find_package(OpenGL)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
add_subdirectory(thirdparty/glfw)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/gli
  ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glfw/include
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/include
)

set(OPENGL_GRAPHICS_ENGINE_NAME "FastEngine")

set(MATH_DIR math)
set(MATH_INTERNAL_DIR ${MATH_DIR}/internal)
set(MATH_BOUNDING_DIR ${MATH_DIR}/bounding)

set(ENGINE_DIR engine)
set(ENGINE_INCLUDE_DIR ${ENGINE_DIR}/include)
set(ENGINE_SOURCE_DIR  ${ENGINE_DIR}/src)
set(ENGINE_GLAD_DIR    ${ENGINE_SOURCE_DIR}/glad)
set(ENGINE_INCLUDE_MATERIAL_DIR ${ENGINE_INCLUDE_DIR}/material)
set(ENGINE_INCLUDE_MESH_DIR     ${ENGINE_INCLUDE_DIR}/mesh)
set(ENGINE_SOURCE_MESH_DIR      ${ENGINE_SOURCE_DIR}/mesh)
set(ENGINE_SOURCE_MATERIAL_DIR  ${ENGINE_SOURCE_DIR}/material)

set(RENDERER_INCLUDE_DIR ${ENGINE_INCLUDE_DIR}/renderer)
set(RENDERER_SOURCE_DIR ${ENGINE_SOURCE_DIR}/renderer)


set(CORE_MATH
  ${MATH_DIR}/common.hpp
  ${MATH_DIR}/matrix.hpp
  ${MATH_DIR}/quaternion.hpp
  ${MATH_DIR}/ray.hpp
  ${MATH_DIR}/vector.hpp
  ${MATH_DIR}/matrix_math.hpp
  ${MATH_DIR}/vector_math.hpp
  ${MATH_DIR}/quaternion_math.hpp
  ${MATH_INTERNAL_DIR}/matrix.inl
  ${MATH_INTERNAL_DIR}/matrix_math.inl
  ${MATH_INTERNAL_DIR}/vector.inl
  ${MATH_INTERNAL_DIR}/vector_math.inl
  ${MATH_INTERNAL_DIR}/quaternion.inl
  ${MATH_INTERNAL_DIR}/quaternion_math.inl
  ${MATH_BOUNDING_DIR}/bound_box.hpp
  ${MATH_BOUNDING_DIR}/bound_cylinder.hpp
  ${MATH_BOUNDING_DIR}/bound_sphere.hpp
)

set(ENGINE_CORE
  ${ENGINE_SOURCE_DIR}/setup.cpp 
  ${ENGINE_INCLUDE_DIR}/setup.hpp
)

set(RENDERER_CORE
  ${RENDERER_INCLUDE_DIR}/renderer.hpp
  ${RENDERER_SOURCE_DIR}/renderer.cpp
  ${RENDERER_INCLUDE_DIR}/command_list.hpp
  ${RENDERER_INCLUDE_DIR}/render_command.hpp
  ${RENDERER_INCLUDE_DIR}/render_target.hpp
  ${RENDERER_SOURCE_DIR}/command_list.cpp
  ${RENDERER_SOURCE_DIR}/render_command.cpp
  ${RENDERER_SOURCE_DIR}/render_target.cpp
)

set(GLAD_CORE 
  ${ENGINE_GLAD_DIR}/glad.c
  ${ENGINE_GLAD_DIR}/glad.h
  ${ENGINE_GLAD_DIR}/khrplatform.h
)

set(MESH_CORE
  ${ENGINE_INCLUDE_MESH_DIR}/mesh.hpp
  ${ENGINE_INCLUDE_MESH_DIR}/vertex.hpp
  ${ENGINE_SOURCE_MESH_DIR}/mesh.cpp
)

set(MATERIAL_CORE
  ${ENGINE_INCLUDE_MATERIAL_DIR}/material.hpp
  ${ENGINE_INCLUDE_MATERIAL_DIR}/shader_program.hpp
  ${ENGINE_SOURCE_MATERIAL_DIR}/material.cpp
  ${ENGINE_SOURCE_MATERIAL_DIR}/shader_program.cpp
)

set(FILE_GLOB
  ${CORE_MATH}
  ${ENGINE_CORE}
  ${GLAD_CORE}
  ${RENDERER_CORE}
  ${MESH_CORE}
  ${MATERIAL_CORE}
)

if (${CMAKE_CXX_COMPILER_ID})
  # Doing some stuff for organization.
  if (MSVC)
    foreach(source IN LISTS FILE_GLOB)
      get_filename_component(source_path "${source}" PATH)
      string(REPLACE "/" "\\" source_path_msvc "${source_path}")
      source_group("${source_path_msvc}" FILES "${source}")
    endforeach()
  endif()
endif()


add_library(${OPENGL_GRAPHICS_ENGINE_NAME} STATIC
  ${FILE_GLOB}
)

target_link_libraries(${OPENGL_GRAPHICS_ENGINE_NAME} 
  glfw
  ${OPENGL_LIBRARIES}
)

add_subdirectory(tests)