// Copyright (c) Mario Garcia, MIT License.
#include "renderer/renderer.hpp"

#include "../glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>


namespace qengine {


GLFWwindow *window = nullptr;


void Engine::Init()
{
  glfwInit();
  if (!window) {
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_TRUE);
    window = glfwCreateWindow(1920, 1080, "Quick Engine", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
  } 
  if (!gladLoadGLLoader((GLADloadproc )glfwGetProcAddress)) {
    std::cout << "Failed to load glad :c\n";
  }
}


bool Engine::WindowIsRunning()
{
  return !glfwWindowShouldClose(window);
}


void Engine::Poll()
{
  glfwPollEvents();
}


void Engine::SwapBuffers()
{
  glfwSwapBuffers(window);
}
} // qengine