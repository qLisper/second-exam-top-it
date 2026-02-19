#ifndef ENCODE_HPP
#define ENCODE_HPP
#include <iostream>
namespace musorin {
  struct pair_t
  {
    size_t count;
    char symbol;
  };
  int parseArgs(int argc, char* argv[], bool& reverse);
  int readAndGroup(pair_t*& pairs, size_t& pairCount);
  void printPairs(const pair_t* pairs, size_t pairCount, bool reverse);
}
#endif
