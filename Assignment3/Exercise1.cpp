#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cassert>
#include <utility>  // std::pair
#include <cstddef>  // std::size_t
using namespace std; 


// (a) Search: public entry. Calls a private index-based helper.
template <typename T>
bool contains_recursive(const std::vector<T>& A, const T& x);
    

// (b) Min & Max: public entry. Calls a private accumulator-style helper.
template <typename T>
std::pair<T,T> minmax_recursive(const std::vector<T>& A);

// -------------------- Private helpers ADT --------------------
namespace detail {

// contains_recursive helper: examine A[idx], recurse on the rest.
// Base case idea: idx == A.size() -> not found.
template <typename T>
bool contains_helper(const std::vector<T>& A, std::size_t idx, const T& x);


// minmax_recursive helper: carry current (min, max) while advancing idx.
// Base case idea: idx == A.size() -> return accumulated (min,max).
template <typename T>
std::pair<T,T> minmax_helper(const std::vector<T>& A,
                             std::size_t idx,
                             T current_min,
                             T current_max);

} 

// ================== IMPLEMENTATION ==================

// ================ Task A =================

// (a) Search entry
template <typename T>
bool contains_recursive(const std::vector<T>& A, const T& x) {
    if (A.empty()) {
        cout << "A is empty, so element isnt there." << endl;
        return false;
    } 
    return detail::contains_helper(A, 0, x);
}

// (a) Search helper
template <typename T>
bool detail::contains_helper(const std::vector<T>& A, std::size_t idx, const T& x) {
    //Base case: We are at the end of the array/vector and if we happen to be here, 
    // then we havent found element x and return false.
    //Otherwise, we turn true if we find x or 
    if (idx == A.size()){
        std::cout << "We searched whole A, couldn't find x element." << endl;
        return false;
    }
    else if (A[idx]== x) {
        std::cout << "We searched vector A and found: " << x << ", at position: " << idx << endl;
        return true; 
    } 
    else {
        return contains_helper(A, idx+1, x);
    }
}

// ================ Task B =================

// (b) Min+Max entry
template <typename T>
std::pair<T,T> minmax_recursive(const std::vector<T>& A) {
    if(A.empty()){
        throw std::invalid_argument("minmax_recurse: empty vector");
    } else {
        return detail::minmax_helper(A, 0, A[0], A[0]);
    }
}

// (b) Min+Max helper
template <typename T>
std::pair<T,T> detail::minmax_helper(const std::vector<T>& A,
                                     std::size_t idx,
                                     T current_min,
                                     T current_max) {
    // BC: If we reach end of the vector, return final min and max.
    // Recursive case: If the current element in the array is higher than current max or lower than current min
    // Update the currentmin or currentmax if that is the case.
    if (idx == A.size()){
        std::cout<<"Min: "<<current_min<<endl;
        std::cout<<"Max: "<<current_max<<endl;
        return {current_min, current_max};
    }
    else if (A[idx] < current_min){ 
        current_min = A[idx];
    }
    else if (A[idx] > current_max){
        current_max = A[idx];
    }
    return minmax_helper(A, idx + 1, current_min, current_max);
}


int main() {
    std::vector<int> v{3,1,4,1,5,9};
    assert(contains_recursive(v, 4) == true );
    assert(contains_recursive(v, 2) == false );

    auto [mn,mx] = minmax_recursive(v);
    assert(mn == 1 && mx == 9);

    return 0;
}
