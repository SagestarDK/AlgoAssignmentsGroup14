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


// ============================ STUBS (fill TODOs) ============================
namespace maze {

bool hasPath(const std::vector<std::string>& input) {
    // TODO:
    // 1) Validate non-empty rectangular grid.
    // 2) Choose coordinate system: convert (1,1) to 0-based (0,0) if needed.
    // 3) Make a modifiable copy if you will mark visited in-place:
    //      auto grid = input;
    //    OR prepare a visited matrix:
    //      std::vector<std::vector<bool>> vis(rows, std::vector<bool>(cols,false));
    // 4) Call dfs(start_r, start_c, ...).
    (void)input; // remove after implementing
    return false; // placeholder
}

bool dfs(int r, int c,
         std::vector<std::string>& grid,
         int rows, int cols) {
    // TODO: Base cases in this order (typical):
    //   a) if out of bounds -> return false
    //   b) if grid[r][c] is 'X' (wall) -> return false
    //   c) if grid[r][c] is already visited mark -> return false
    //   d) if grid[r][c] is 'E' -> return true
    //
    // TODO: Mark current as visited (choose a char like '.').
    //
    // TODO: Try 4 directions (no loops required; just 4 recursive calls):
    //   if (dfs(r-1, c, ...)) return true;   // up
    //   if (dfs(r, c+1, ...)) return true;   // right
    //   if (dfs(r+1, c, ...)) return true;   // down
    //   if (dfs(r, c-1, ...)) return true;   // left
    //
    // TODO: (Optional) Unmark before returning false if you want to preserve grid.
    (void)r; (void)c; (void)grid; (void)rows; (void)cols; // remove after implementing
    return false; // placeholder
}

inline bool inBounds(int r, int c, int rows, int cols) {
    // TODO: return true iff 0 <= r < rows and 0 <= c < cols.
    (void)r; (void)c; (void)rows; (void)cols; // remove after implementing
    return false; // placeholder
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
