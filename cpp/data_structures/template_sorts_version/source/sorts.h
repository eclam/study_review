#ifndef SORTS_H_
#define SORTS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <class T>
class sorts
{
  private:
    // T data_vector;
    const void sortsPrintVector(std::vector<T> input_vector);

    // QuickSort Helpers
    int quickSortPartition(std::vector<T>& input_vector, int begin, int end);
    void quickSortHelper(std::vector<T>& input_vector, int begin, int end);

    std::vector<T> mergeSortHelper(std::vector<T>& input_vector);
    std::vector<T>& mergeSortStitcher(std::vector<T>& input_vector, std::vector<T>& left, std::vector<T>& right);

  public:
    // sorts(std::vector<T> input_vector);
    // sorts();
    // ~sorts();

    std::vector<T> insertionSort(std::vector<T> input_vector);
    std::vector<T> insertionSortFromEnd(std::vector<T> input_vector);

    std::vector<T> bubbleSort(std::vector<T> input_vector);
    std::vector<T> bubbleSortFromEnd(std::vector<T> input_vector);

    std::vector<T> selectionSort(std::vector<T> input_vector);
    std::vector<T> selectionSortFromEnd(std::vector<T> input_vector);

    std::vector<T> quickSort(std::vector<T> input_vector); // takes first iterator as pivot

    std::vector<T> mergeSort(std::vector<T> input_vector);

};

template <class T>
const void sorts<T>::sortsPrintVector(const std::vector<T> input_vector)
{
  if (!input_vector.empty())
  {
    auto end_check = input_vector.end()-1; // ptr to end val

    for (auto &i : input_vector)
    {
      std::cout << i;
      if (&i != &(*end_check)) // get val then get addr to see if addr == i's addr
      {
        std::cout << ", ";
      }
    }

    std::cout << "\n";
  }
}

template <class T>
std::vector<T>& sorts<T>::mergeSortStitcher(std::vector<T>& input_vector, std::vector<T>& left, std::vector<T>& right)
{
  auto left_iter = left.begin();
  auto right_iter = right.begin();
  while (left_iter != left.end() && right_iter != right.end())
  {
    if (*left_iter < *right_iter)
    {
      std::move(left_iter, left_iter+1, std::back_inserter(input_vector));
      ++left_iter;
    }
    else
    {
      std::move(right_iter, right_iter+1, std::back_inserter(input_vector));
      ++right_iter;
    }
  }

  while (left_iter != left.end())
  {
    std::move(left_iter, left_iter+1, std::back_inserter(input_vector));
    ++left_iter;
  }

  while (right_iter != right.end())
  {
    std::move(right_iter, right_iter+1, std::back_inserter(input_vector));
    ++right_iter;
  }

  sortsPrintVector(input_vector);

  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::mergeSortHelper(std::vector<T>& input_vector)
{
  if (input_vector.size() == 1)
  {
    sortsPrintVector(input_vector);
    return input_vector;
  }

  int dist = std::distance(input_vector.begin(), input_vector.end())/2;
  auto split_iterator = input_vector.begin();
  std::advance(split_iterator,dist);

  std::vector<T> left;
  std::vector<T> right;

  std::move(input_vector.begin(), split_iterator, std::back_inserter(left));
  std::move(split_iterator, input_vector.end(), std::back_inserter(right));
  input_vector.erase(input_vector.begin(), input_vector.end());

  mergeSortHelper(left);
  mergeSortHelper(right);

  return mergeSortStitcher(input_vector, left, right);
}

template <class T>
std::vector<T> sorts<T>::mergeSort(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);

  input_vector = mergeSortHelper(input_vector);

  sortsPrintVector(input_vector);
  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::insertionSort(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);
  for (auto i = input_vector.begin()+1; i != input_vector.end(); ++i)
  {
    for (auto k = i-1; k >= input_vector.begin() && *k > *(k+1); --k)
    {
      std::iter_swap(k, k+1);
      sortsPrintVector(input_vector);
    }
  }
  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::insertionSortFromEnd(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);
  for (auto i = input_vector.end()-1; i != input_vector.begin()-1; --i)
  {
    for (auto k = i-1; k >= input_vector.begin() && *k > *(k+1); ++k)
    {
      std::iter_swap(k, k+1);
      sortsPrintVector(input_vector);
    }
  }

  // for (auto i = input_vector.rbegin()+1; i != input_vector.rend(); ++i)
  // {
  //   for (auto k = i-1; k >= input_vector.rbegin() && *k < *(k+1); --k)
  //   {
  //     std::iter_swap(k, k+1);
  //     sortsPrintVector(input_vector);
  //   }
  // }
  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::bubbleSort(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);
  for (auto k = input_vector.end()-1; k != input_vector.begin(); --k)
  {
    bool swap_flag = false;
    for (auto i = input_vector.begin(); i != k; ++i)
    {
      if (*i > *(i+1))
      {
        std::iter_swap(i,i+1);
        swap_flag = true;
      }
      sortsPrintVector(input_vector);
    }
    if (swap_flag == false)
    {
      break;
    }
  }

  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::bubbleSortFromEnd(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);
  for (auto k = input_vector.begin(); k != input_vector.end(); ++k)
  {
    bool swap_flag = false;
    for (auto i = input_vector.end()-1; i != k-1; --i)
    {
      if (*i < *(i-1))
      {
        std::iter_swap(i,i-1);
        swap_flag = true;
      }
      sortsPrintVector(input_vector);
    }
    if (swap_flag == false)
    {
      break;
    }
  }

  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::selectionSort(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);
  for (auto i = input_vector.begin(); i != input_vector.end(); ++i)
  {
    for (auto k = i+1; k != input_vector.end(); ++k)
    {
      if (*k < *i)
      {
        std::iter_swap(i, k);
      }

      sortsPrintVector(input_vector);
    }
  }

  return input_vector;
}

template <class T>
std::vector<T> sorts<T>::selectionSortFromEnd(std::vector<T> input_vector)
{
  sortsPrintVector(input_vector);
  for (auto i = input_vector.end()-1; i != input_vector.begin()-1; --i)
  {
    for (auto k = i-1; k != input_vector.begin()-1; --k)
    {
      if (*k > *i)
      {
        std::iter_swap(i, k);
      }

      sortsPrintVector(input_vector);
    }
  }

  return input_vector;
}

template <class T>
int sorts<T>::quickSortPartition(std::vector<T>& input_vector, int begin, int end)
{
  auto pivot = input_vector[end];
  auto left_ptr = begin;
  auto right_ptr = end-1;

  while (true)
  {
    for (int i = left_ptr; i < end && input_vector[i] < pivot; ++i)
    {
      ++left_ptr;
    }

    for (int i = right_ptr; i > 0 && input_vector[i] > pivot; ++i)
    {
      --right_ptr;
    }

    if (left_ptr >= right_ptr)
      break;
    else
    {
      std::swap(input_vector[left_ptr], input_vector[right_ptr]);
      sortsPrintVector(input_vector);
    }
  }
  std::swap(input_vector[left_ptr], input_vector[end]);
  sortsPrintVector(input_vector);

  return left_ptr;
}

template <class T>
void sorts<T>::quickSortHelper(std::vector<T>& input_vector, int begin, int end)
{
  if (end - begin > 0)
  {
    sortsPrintVector(input_vector);
    auto partition_index = quickSortPartition(input_vector, begin, end);

    quickSortHelper(input_vector, begin, partition_index-1);
    quickSortHelper(input_vector, partition_index+1, end);
  }
}

template <class T>
std::vector<T> sorts<T>::quickSort(std::vector<T> input_vector)
{
  quickSortHelper(input_vector, 0, input_vector.size()-1);
  sortsPrintVector(input_vector);
  return input_vector;
}

#endif