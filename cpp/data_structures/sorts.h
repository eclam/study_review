#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

class sorts
{
  private:
    // std::vector<int> data_vector;
    const void sortsPrintVector(std::vector<int> input_vector);

  public:
    // sorts(std::vector<int> input_vector);
    sorts();
    ~sorts();

    std::vector<int> insertionSort(std::vector<int> input_vector);
    std::vector<int> insertionSortFromEnd(std::vector<int> input_vector);
};

#endif
