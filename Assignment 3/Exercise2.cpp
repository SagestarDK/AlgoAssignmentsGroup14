// ============================================================================
// Exercise 2 – Recursive triangle(m, n) skeleton (NO IMPLEMENTATION INSIDE)
// Goal:
//   Print lines of '*' starting at m chars, increasing by 1 each line up to n,
//   then mirror back down to m. Example for triangle(4,6):
//     ****
//     *****
//     ******
//     *****
//     ****
//
// Approach:
//   • Use recursion only (no loops in the core printing helpers).
//   • Separate concerns:
//       1) print_line(k): recursively prints exactly k '*' and a newline.
//       2) triangle(m,n): validates and delegates to a recursive driver.
//       3) tri_driver(curr, m, n): prints the "up" then "down" pattern.
//         (You can do this in one function by printing at curr, recursing,
//          then printing again on the way back up.)
// Complexity (complete these in your write-up):
//   • Time:  TODO – express as a function of (n-m+1) and characters printed.
//   • Space: TODO – recursion depth (what’s the maximum?)
// ============================================================================

#include <iostream>
#include <stdexcept>

namespace tri {

// Public API (students implement the bodies below with recursion only).
void triangle(int m, int n);

// --- Private helpers (implement with recursion only; NO loops) ---
// 1) Print exactly k '*' characters followed by '\n'.
void print_line(int k);

// 2) Recursive driver that handles the up-then-down shape.
//    Invariant idea: m <= curr <= n when called.
void tri_driver(int curr, int m, int n);

} // namespace tri


// ============================ STUBS (fill TODOs) ============================
namespace tri {

void triangle(int m, int n) {
    // TODO: Validate input: if m > n, decide policy (swap? throw? return?).
    // TODO: Kick off recursion at curr = m (or adjusted value).
    (void)m; (void)n; // remove after implementing
}

void print_line(int k) {
    // TODO: Base case: when to stop printing and emit newline.
    // TODO: Recursive case: print one '*', recurse with k-1.
    (void)k; // remove after implementing
}

void tri_driver(int curr, int m, int n) {
    // TODO: Base case: when curr passes bounds (what should happen?).
    // TODO: Recursive pattern (choose one):
    //   Option A (single pass with mirror via post-order):
    //     1) print_line(curr)
    //     2) recurse to next size (curr+1)
    //     3) print_line(curr) again when unwinding, but only if curr < n
    //
    //   Option B (two explicit phases via parameters/flags):
    //     document your choice and keep it recursive.
    (void)curr; (void)m; (void)n; // remove after implementing
}

} // namespace tri


// ============================== QUICK CHECKS ================================
// After you implement, uncomment and try:
// int main() {
//     tri::triangle(4, 6);
//     std::cout << "---\n";
//     tri::triangle(3, 3); // single line
//     return 0;
// }
// ============================================================================
