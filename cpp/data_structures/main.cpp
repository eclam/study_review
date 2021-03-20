#include <iostream>
#include <vector>
#include "sorts.h"


int main()
{
  std::vector<int> unsorted_vector = {5, 1, 3, 4, 2, 6};
  std::vector<int> sorted_vector = {1, 2, 3, 4, 5, 6};
  std::vector<int> reverse_vector = {6, 5, 4, 3, 2, 1};
  std::vector<int> null_vector = {};

  sorts test_sort(unsorted_vector);
  sorts test_sort2(sorted_vector);

  return 0;
}