#include <iostream>
#include <vector>
#include "sorts.h"

sorts::sorts(std::vector<int> input_vector)
{
  for(std::vector<int>::iterator i = input_vector.begin(); i != input_vector.end(); ++i) {
    std::cout << *i << std::endl;
    data_vector.push_back(*i);
  }
}

sorts::~sorts()
{
}

void sorts::sortsPrintVector()
{
  for(std::vector<int>::iterator i = data_vector.begin(); i != data_vector.end(); ++i) {
      std::cout << *i << std::endl;
  }
}