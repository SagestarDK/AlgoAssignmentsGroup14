// ============================================================================
// Exercise 4 – Recursive maze path (skeleton ONLY; no implementation)
// Problem:
//   Given a ROWS x COLS char grid with:
//     'X' = wall, ' ' (space) = open cell, one 'E' = exit.
//   Start at position (1,1) (row 1, col 1, 0-based or 1-based? you decide).
//   Return true iff there exists a path from start to 'E'.
//
// Approach (simple DFS/backtracking):
//   - Keep a visited matrix OR mark cells temporarily (e.g., '.')
//   - From a cell, try up to 4 neighbors (up, right, down, left).
//   - Respect bounds + walls + visited.
//   - Base cases: out of bounds, wall, visited => false; at 'E' => true.
//   - Backtrack on failure (unmark if you chose marking).
//
// Complexity (fill in your hand-in):
//   - Time:  TODO – in worst case proportional to number of cells.
//   - Space: TODO – recursion depth up to number of cells (or path length).
// ============================================================================

#include <vector>
#include <string>

namespace maze {

// Public API: returns true if a path exists; false otherwise.
// Pre: grid is rectangular and contains exactly one 'E'.
// Note: decide if input uses 0-based or 1-based start; convert accordingly.
bool hasPath(const std::vector<std::string>& grid);

// -------------------- Private helpers (implement below) --------------------

// DFS with backtracking.
// Parameters:
//   r, c     : current position (0-based indices recommended)
//   grid     : working copy if you choose to mark visited in-place; OR
//              const ref + separate visited matrix.
// Returns true if exit is reachable from (r,c).
bool dfs(int r, int c,
         std::vector<std::string>& grid,            // if marking in-place
         // Alternatively, comment the line above and use:
         // const std::vector<std::string>& grid,
         // std::vector<std::vector<bool>>& visited,
         int rows, int cols);

// Optional tiny utility: check bounds.
inline bool inBounds(int r, int c, int rows, int cols);

} // namespace maze


namespace maze {

bool hasPath(const std::vector<std::string>& input) {
    
}

bool dfs(int r, int c,
         std::vector<std::string>& grid,
         int rows, int cols) {

}

inline bool inBounds(int r, int c, int rows, int cols) {

}

} // namespace maze


// ============================== QUICK CHECKS ================================
// After you implement, you can try:
//
// int main() {
//     std::vector<std::string> g = {
//         " XXXXX",
//         " X  X",
//         " XX X",
//         "    E"
//     }; // decide whether first char is padding or real cell
//     // Start at (1,1) per problem (convert as needed).
//     bool ok = maze::hasPath(g);
//     // std::cout << std::boolalpha << ok << "\n";
//     return 0;
// }
// ============================================================================
