#include <chrono>

#include "ism_vector.h"

#include "class-integer.hpp"
#include "class-matrix.hpp"
#include "class-bint.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace sjtu = insomnia;

void complex_test()
{
  std::cout << "Supplementary test for large amounts of data ..." << std::endl;
  sjtu::vector<Diamond::Matrix<Util::Bint>> myVec;
  for (int i = 1; i <= 1926; ++i)
    myVec.push_back(Diamond::Matrix<Util::Bint>(i % 8 + 1, i % 17 + 1, Util::Bint(i * 817)));
  int o = 1234;
  while (o--)
    myVec.pop_back();
  myVec = myVec;
  int _ = 20, __ = myVec.size();
  while (_--)
  {
    if (_ % 2 == 0)
      std::cout << myVec[_][0][0] << std::endl;
    else
      std::cout << myVec[__ - _][0][0] << std::endl;
  }
  std::cout << "Finished!" << std::endl;
}

int main()
{
  auto s = std::chrono::high_resolution_clock::now();
  complex_test();
  auto e = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count() << std::endl;
}