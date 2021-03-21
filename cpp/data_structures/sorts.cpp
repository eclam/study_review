#include <iostream>
#include <vector>
#include "sorts.h"

// sorts::sorts(std::vector<int> input_vector)
// {
//   for(std::vector<int>::iterator i = input_vector.begin(); i != input_vector.end(); i++) {
//     input_vector.push_back(*i);
//   }
// }

sorts::sorts()
{
}

sorts::~sorts()
{
}

const void sorts::sortsPrintVector(const std::vector<int> input_vector)
{
  if (!input_vector.empty())
  {
    auto end_check = input_vector.end()-1; // ptr to end val

    for(auto &i : input_vector)
    {
      std::cout << i;
      if (&i != &(*end_check)) // get val then get addr to see if addr == i's addr
        std::cout << ", ";
    }

    std::cout << std::endl;
  }
}

std::vector<int> sorts::insertionSort(std::vector<int> input_vector)
{
  sortsPrintVector(input_vector);
  for(auto i = input_vector.begin()+1; i != input_vector.end(); i++)
  {
    for (auto k = i-1; k >= input_vector.begin() && *k > *(k+1); k--)
    {
      std::iter_swap(k, k+1);
      sortsPrintVector(input_vector);
    }
  }
  return input_vector;
}

std::vector<int> sorts::insertionSortFromEnd(std::vector<int> input_vector)
{
  sortsPrintVector(input_vector);
  for(auto i = input_vector.end()-1; i != input_vector.begin()-1; i--)
  {
    for (auto k = i-1; k >= input_vector.begin() && *k > *(k+1); k++)
    {
      std::iter_swap(k, k+1);
      sortsPrintVector(input_vector);
    }
  }
  return input_vector;
}

