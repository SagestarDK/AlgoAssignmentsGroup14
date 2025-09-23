// ============================================================================
// Recursion – Minimal Skeleton (no solutions inside)
// Problems:
//   (a) Recursively search for x in array A -> return true/false.
//   (b) Recursively find BOTH minimum and maximum in A.
// Approach: Straightforward LINEAR recursion (easiest & quickest).
//
// Fill in the TODOs only. Keep core logic recursive (no loops inside them).
//
// Complexity notes to write in your report (complete the sentences):
//   • contains_recursive: Time = Θ(N) worst-case (T(n)=T(n-1)+Θ(1)), 
//                         Space = Θ(N) due to recursion depth.
//   • minmax_recursive:  Time = Θ(N) (T(n)=T(n-1)+Θ(1)),
//                        Space = Θ(N) due to recursion depth.
// ============================================================================

#include <vector>
#include <stdexcept>
#include <limits>
#include <utility>  // std::pair
#include <cstddef>  // std::size_t

// -------------------- API you will implement --------------------

// (a) Search: public entry. Calls a private index-based helper.
template <typename T>
bool contains_recursive(const std::vector<T>& A, const T& x);

// (b) Min & Max: public entry. Calls a private accumulator-style helper.
// Pre: A.size() > 0 (decide: throw or handle explicitly)
template <typename T>
std::pair<T,T> minmax_recursive(const std::vector<T>& A);

// -------------------- Private helpers (implement below) --------------------
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

} // namespace detail

// =========================== STUBS (fill TODOs) =============================

// (a) Search entry
template <typename T>
bool contains_recursive(const std::vector<T>& A, const T& x) {
    // TODO: Optionally handle empty vector quickly (return false).
    // TODO: Delegate to helper starting at index 0.
    (void)A; (void)x;               // remove after implementing
    return false;                   // placeholder
}

// (a) Search helper
template <typename T>
bool detail::contains_helper(const std::vector<T>& A, std::size_t idx, const T& x) {
    // TODO: Base case: if idx == A.size() -> return false.
    // TODO: Recursive case:
    //   - Check current element
    //   - If match -> return true
    //   - Else -> return contains_helper(A, idx+1, x)
    (void)A; (void)idx; (void)x;    // remove after implementing
    return false;                   // placeholder
}

// (b) Min+Max entry
template <typename T>
std::pair<T,T> minmax_recursive(const std::vector<T>& A) {
    // TODO: If A is empty -> decide policy (throw std::invalid_argument or similar).
    // TODO: Initialize current_min/current_max with A[0].
    // TODO: Call helper starting at idx = 1.
    (void)A;                        // remove after implementing
    return {T{}, T{}};              // placeholder
}

// (b) Min+Max helper
template <typename T>
std::pair<T,T> detail::minmax_helper(const std::vector<T>& A,
                                     std::size_t idx,
                                     T current_min,
                                     T current_max) {
    // TODO: Base case: if idx == A.size() -> return {current_min, current_max}.
    // TODO: Recursive case:
    //   - Update current_min/current_max using A[idx]
    //   - Recurse on idx+1 with updated accumulators
    (void)A; (void)idx; (void)current_min; (void)current_max; // remove after implementing
    return {T{}, T{}};               // placeholder
}

// ============================== OPTIONAL TESTS ==============================
// Add your own tests or a main() that calls the functions with small vectors.
// Keep loops OUT of the recursive core functions, but feel free to use loops
// here to generate input cases if you want.
// ============================================================================

int main() {
    // TODO: add a few quick checks when you’ve implemented:
    // std::vector<int> v{3,1,4,1,5,9};
    // assert( contains_recursive(v, 4) == true );
    // assert( contains_recursive(v, 2) == false );
    // auto [mn,mx] = minmax_recursive(v);
    // assert(mn == 1 && mx == 9);
    return 0;
}
