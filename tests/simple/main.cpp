#include <iostream>
#include <iomanip>
#include "renderer/renderer.hpp"
#include "matrix.hpp"
#include "matrix_math.hpp"


int main(int c, char *argv[]) 
{
  math::Mat4 mat = math::PerspectiveLH(45.0f, 0.5f, 0.1f, 1000.0f);

  for (math::uint32 i = 0; i < 4; ++i) {
    for (math::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
  qengine::Engine engine;
  engine.Init();

  while (engine.WindowIsRunning()) {
    engine.SwapBuffers();
    engine.Poll();
  }
  return 0;
}