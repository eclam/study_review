#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

class sorts
{
  private:
    std::vector<int> data_vector;


  public:
    sorts(std::vector<int> input_vector);
    ~sorts();

    void sortsPrintVector();
};

#endif
