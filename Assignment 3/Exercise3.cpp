// ============================================================================
// Exercise 3 – Booklet printing (skeleton ONLY; no implementations)
// Problem:
//   Implement bookletPrint(int startPage, int endPage) using RECURSION.
//   Each sheet lists 4 pages in this order:  lo, lo+1, hi-1, hi
//   (as in the example: bookletPrint(1,8) -> sheet1: 1 2 7 8, sheet2: 3 4 5 6)
// Assumptions:
//   • Total pages (endPage - startPage + 1) is a multiple of 4.
//   • Pages are consecutive integers.
//
// Approach (pick this simple one):
//   - Use a recursive helper that takes (lo, hi, sheetNo).
//   - For each call, output: "Sheet X contains pages lo, lo+1, hi-1, hi"
//   - Recurse with (lo+2, hi-2, sheetNo+1) until done.
//
// Complexity (fill these in your hand-in):
//   • Time:  TODO – proportional to number of sheets = (end-start+1)/4.
//   • Space: TODO – recursion depth equals number of sheets.
// ============================================================================

#include <iostream>
#include <stdexcept>
#include <string>

namespace booklet {

// Public API (students implement bodies below)
void bookletPrint(int startPage, int endPage);

// --- Private helpers (implement with recursion only; no loops) ---
void bookletHelper(int lo, int hi, int sheetNo);

// Optional: a single-responsibility function for printing one line.
// Keep it simple; you may also inline this inside the helper if preferred.
void printSheetLine(int sheetNo, int p1, int p2, int p3, int p4);

} // namespace booklet


// ============================ STUBS (fill TODOs) ============================
namespace booklet {

void bookletPrint(int startPage, int endPage) {
    // TODO: Validate inputs:
    //   - startPage <= endPage
    //   - (endPage - startPage + 1) % 4 == 0 (decide: assert/throw)
    // TODO: Start recursion with sheetNo = 1
    (void)startPage; (void)endPage; // remove after implementing
}

void bookletHelper(int lo, int hi, int sheetNo) {
    // TODO: Base case: when all pages are assigned.
    //        (Hint: once lo > hi, or equivalently lo+1 > hi)
    // TODO: Recursive step:
    //   - Compute p1 = lo, p2 = lo+1, p3 = hi-1, p4 = hi
    //   - printSheetLine(sheetNo, p1, p2, p3, p4)
    //   - Recurse with (lo+2, hi-2, sheetNo+1)
    (void)lo; (void)hi; (void)sheetNo; // remove after implementing
}

void printSheetLine(int sheetNo, int p1, int p2, int p3, int p4) {
    // TODO: Format exactly as required by your assignment, e.g.:
    //   "Sheet X contains pages a, b, c, d"
    (void)sheetNo; (void)p1; (void)p2; (void)p3; (void)p4; // remove after implementing
}

} // namespace booklet


// ============================== QUICK CHECKS ================================
// After implementing, try:
//
// int main() {
//     booklet::bookletPrint(1, 8);
//     // Expected:
//     // Sheet 1 contains pages 1, 2, 7, 8
//     // Sheet 2 contains pages 3, 4, 5, 6
//     return 0;
// }
//
// ============================================================================
