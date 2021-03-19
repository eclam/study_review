#include <iostream>
#include <vector>
#include "sorts.h"

sorts::sorts(std::vector<int> input_vector)
{
  data_vector = input_vector;
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