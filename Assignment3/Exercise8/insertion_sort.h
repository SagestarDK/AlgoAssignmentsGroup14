#ifndef _INTRO_SORT_H_
#define _INTRO_SORT_H_

#include <vector>
#include <cassert>
#include "insertion_sort.h"  // has iterator overload
#include "quick_sort.h"      // provides partition(a,left,right)

using std::vector;

static constexpr int useInsertion = 16;

template <typename T>
void introSort(vector<T>& a, int left, int right) {
    if (left >= right) return;                          // base case
    assert(left >= 0 && right < static_cast<int>(a.size()));

    const int size = right - left + 1;
    if (size <= useInsertion) {
        // sort subarray [left, right] via iterator overload
        insertionSort(a.begin() + left, a.begin() + right + 1);
        return;
    }

    // partition and sort both halves (two separate ifs, NOT else-if)
    int pivot = partition(a, left, right);
    if (pivot - 1 > left)  introSort(a, left,     pivot - 1);
    if (pivot + 1 < right) introSort(a, pivot + 1, right);
}

template <typename T>
void introSort(vector<T>& a) {
    if (!a.empty()) introSort(a, 0, static_cast<int>(a.size()) - 1);
}

#endif
