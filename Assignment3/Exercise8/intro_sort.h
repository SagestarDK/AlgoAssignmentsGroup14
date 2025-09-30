#ifndef _INTRO_SORT_H_
#define _INTRO_SORT_H_

#include <vector>
#include <cassert>
#include "insertion_sort.h"  // iterator-based overload: insertionSort(begin,end)
#include "quick_sort.h"      // partition(...)

static constexpr int kInsertionCutoff = 1024;

template <typename Comparable>
void introSort(std::vector<Comparable>& a, int left, int right) {
    // Guard empty and enforce sane bounds
    if (a.empty()) return;
    assert(left >= 0);
    assert(right >= 0);
    assert(left <= right);
    assert(static_cast<int>(a.size()) - 1 >= right);

    // Base case: 0 or 1 element
    if (left >= right) return;

    const int size = right - left + 1;

    if (size <= kInsertionCutoff) {
        // insertionSort expects [begin, end) — so add +1 to include 'right'
        insertionSort(a.begin() + left, a.begin() + right + 1);
        return;
    }

    // Quicksort step (median-of-three partition from your quick_sort.h)
    const int pivot = partition(a, left, right);

    // Recurse on both sides (base case above will stop at size <= 1)
    introSort(a, left, pivot - 1);
    introSort(a, pivot + 1, right);
}

template <typename Comparable>
void introSort(std::vector<Comparable>& a) {
    if (!a.empty()) {
        introSort(a, 0, static_cast<int>(a.size()) - 1);
    }
}

#endif // _INTRO_SORT_H_
