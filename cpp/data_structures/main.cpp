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

  // auto insertion_sort_test = test_sorts.insertionSort(reverse_sorted_vector);
  // auto insertion_sort_test_from_end = test_sorts.insertionSortFromEnd(reverse_sorted_vector);

  // auto bubble_sort_test = test_sorts.bubbleSort(reverse_sorted_vector);
  // auto bubble_sort_test_from_end = test_sorts.bubbleSortFromEnd(reverse_sorted_vector);

  // auto selection_sort_test = test_sorts.selectionSort(reverse_sorted_vector);
  // auto selection_sort_test = test_sorts.selectionSortFromEnd(reverse_sorted_vector);

  // auto quick_sort_test = test_sorts.quickSort(reverse_sorted_vector);

  return 0;
}