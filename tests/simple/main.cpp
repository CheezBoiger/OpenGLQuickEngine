#include <iostream>
#include <iomanip>
#include "matrix.hpp"


int main(int c, char *argv[]) 
{
  math::Mat4 mat = math::Mat4::Identity();

  for (math::uint32 i = 0; i < 4; ++i) {
    for (math::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(5) << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
  
  std::cin.ignore();
  return 0;
}