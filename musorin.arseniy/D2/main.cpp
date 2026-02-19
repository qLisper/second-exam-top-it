// main.cpp
#include "encode.hpp"
int main(int argc, char* argv[])
{
  using namespace musorin;
  bool reverse = false;
  if (parseArgs(argc, argv, reverse) != 0)
  {
    std::cerr << "Error: invalid arguments\n";
    return 1;
  }
  pair_t* pairs = nullptr;
  size_t pairCount = 0;
  const int readResult = readAndGroup(pairs, pairCount);
  if (readResult == -2)
  {
    std::cerr << "Error: memory allocation failed\n";
    delete[] pairs;
    return 1;
  }
  printPairs(pairs, pairCount, reverse);
  delete[] pairs;
  return 0;
}
