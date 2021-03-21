#include <iostream>
#include <vector>
#include "sorts.h"


int main()
{
  std::vector<int> unsorted_vector = {5, 1, 3, 4, 2, 6};
  std::vector<int> sorted_vector = {1, 2, 3, 4, 5, 6};
  std::vector<int> reverse_sorted_vector = {6, 5, 4, 3, 2, 1};
  std::vector<int> null_vector = {};

  std::vector<char> char_vector = {'a', 'd', 'b', 'c','e','z','s','x'};
  sorts test_sorts;

  auto reverse_sorted = test_sorts.insertionSort(reverse_sorted_vector);
  auto reverse_sorted_from_end = test_sorts.insertionSortFromEnd(reverse_sorted_vector);

  return 0;
}