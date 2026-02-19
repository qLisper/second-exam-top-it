#include "encode.hpp"
#include <cstring>
int musorin::parseArgs(const int argc, char* argv[], bool& reverse)
{
  reverse = false;
  if (argc == 1)
  {
    return 0;
  }
  if (argc == 2 && std::strcmp(argv[1], "reverse") == 0)
  {
    reverse = true;
    return 0;
  }
  return -1;
}
int musorin::readAndGroup(pair_t*& pairs, size_t& pairCount)
{
  const size_t initialCapacity = 8;
  size_t capacity = initialCapacity;
  pairCount = 0;
  try
  {
    pairs = new pair_t[capacity];
  }
  catch (...)
  {
    pairs = nullptr;
    return -2;
  }
  char ch = 0;
  while (std::cin.get(ch))
  {
    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
    {
      continue;
    }
    if (pairCount > 0 && pairs[pairCount - 1].symbol == ch)
    {
      ++pairs[pairCount - 1].count;
      continue;
    }
    if (pairCount == capacity)
    {
      const size_t newCapacity = capacity * 2;
      pair_t* newPairs = nullptr;
      try
      {
        newPairs = new pair_t[newCapacity];
      }
      catch (...)
      {
        delete[] pairs;
        pairs = nullptr;
        return -2;
      }
      for (size_t i = 0; i < pairCount; ++i)
      {
        newPairs[i] = pairs[i];
      }
      delete[] pairs;
      pairs = newPairs;
      capacity = newCapacity;
    }
    pairs[pairCount].count = 1;
    pairs[pairCount].symbol = ch;
    ++pairCount;
  }
  return 0;
}
void musorin::printPairs(const pair_t* pairs,
    const size_t pairCount, const bool reverse)
{
  if (pairCount == 0)
  {
    std::cout << "\n";
    return;
  }
  if (reverse)
  {
    for (size_t i = pairCount; i > 0; --i)
    {
      std::cout << pairs[i - 1].count << " "
          << pairs[i - 1].symbol << "\n";
    }
  }
  else
  {
    for (size_t i = 0; i < pairCount; ++i)
    {
      std::cout << pairs[i].count << " "
          << pairs[i].symbol << "\n";
    }
  }
}
