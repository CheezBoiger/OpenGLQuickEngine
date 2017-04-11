// Copyright(c) Mario Garcia, MIT License.
#pragma once

#include "command_list.hpp"
#include "render_target.hpp"
#include "mesh/mesh.hpp"
#include "material/material.hpp"



namespace qengine {


// Quick Graphics engine. For Practice.
class Engine {
public:

  void Init();
  bool WindowIsRunning();
  void Poll();
  void SwapBuffers();
  
private:
};
} // qengine