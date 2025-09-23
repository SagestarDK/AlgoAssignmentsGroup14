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

//validates input and starts recursion
void bookletPrint(int startPage, int endPage) {
        //Check if inputs are valid.
    if (startPage > endPage) {
        throw std::invalid_argument("startPage must be <= endPage");
    }
    if ((endPage - startPage + 1) % 4 != 0) {
        throw std::invalid_argument("Total pages must be a multiple of 4");
    }

    //start recursion
    bookletHelper(startPage, endPage, 1); // start with sheet 1
    }


//recursive worker, assigns 4 pages per sheet
void bookletHelper(int lo, int hi, int sheetNo) {
    if(lo > hi){return;} // base case: all pages used
    booklet::printSheetLine(sheetNo, lo, lo+1, hi-1, hi); // assign 4 pages
    bookletHelper(lo+2, hi-2, sheetNo+1);  // recurse inward
}

void printSheetLine(int sheetNo, int p1, int p2, int p3, int p4) {
    std:: cout << "Sheet: " << sheetNo << " contains pages: " 
    << p1 << ", " << p2 << ", " << p3 << ", " << p4 << std::endl;
} 
}

int main() {
    booklet::bookletPrint(1, 8);
    // Expected:
    // Sheet 1 contains pages 1, 2, 7, 8
    // Sheet 2 contains pages 3, 4, 5, 6
    return 0;
}
