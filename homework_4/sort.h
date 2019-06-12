// Library calls for sorting vectors of comparable items.

#ifndef HOMEWORK_4_SORT
#define HOMEWORK_4 SORT

#include <cstdint>
#include <vector>

namespace homework_4 {

template <class T>
void BubbleSort(std::vector<T>* vec);

template <class T>
void InsertionSort(std::vector<T>* vec);

template <class T>
void QuickSort(std::vector<T>* vec);

template <class T>
void MergeSort(std::vector<T>* vec);

}  // namespace homework_4

#endif  // HOMEWORK_4_SORT
