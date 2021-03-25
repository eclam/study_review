#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

class sorts
{
  private:
    // std::vector<int> data_vector;
    const void sortsPrintVector(std::vector<int> input_vector);

    // QuickSort Helpers
    int quickSortPartition(std::vector<int> &input_vector, int begin, int end);
    std::vector<int> quickSortHelper(std::vector<int> &input_vector, int begin, int end);

  public:
    // sorts(std::vector<int> input_vector);
    sorts();
    ~sorts();

    std::vector<int> insertionSort(std::vector<int> input_vector);
    std::vector<int> insertionSortFromEnd(std::vector<int> input_vector);

    std::vector<int> bubbleSort(std::vector<int> input_vector);
    std::vector<int> bubbleSortFromEnd(std::vector<int> input_vector);

    std::vector<int> selectionSort(std::vector<int> input_vector);
    std::vector<int> selectionSortFromEnd(std::vector<int> input_vector);

    std::vector<int> quickSort(std::vector<int> input_vector); // takes first iterator as pivot

    std::vector<int> mergeSort(std::vector<int> input_vector);

};

#endif
