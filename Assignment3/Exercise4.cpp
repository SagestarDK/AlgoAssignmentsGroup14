#include <iostream>
#include <vector>
#include <string>

namespace maze {


bool hasPath(const std::vector<std::string>& grid);


bool dfs(int r, int c,
         std::vector<std::string>& grid,            
         int rows, int cols);

inline bool inBounds(int r, int c, int rows, int cols);

} // namespace maze


namespace maze {

bool hasPath(const std::vector<std::string>& input) {
    //Make a copy so we cam mark visited cells.
    auto grid = input;
    int rows = grid.size();
    if (rows==0) return false;
    int cols = grid[0].size();

    //Start in 1.1
    return dfs(1, 1, grid, rows, cols);
}

bool dfs(int r, int c,
         std::vector<std::string>& grid,
         int rows, int cols) {
        // Base case, if out of bounds or we hit a wall, return false. 
        //If we hit exit, hit true.
        if (!inBounds(r,c,rows,cols)) return false;
        if (grid[r][c] == 'X') return false; //Wall or already visited.
        if (grid[r][c] == 'E') return true;

        // Mark visited
        grid[r][c] = 'X';
        
        // Recursive step, explore all 4 directions.
        if (dfs(r+1,c,grid,rows,cols)) return true; //down
        if (dfs(r-1,c,grid,rows,cols)) return true; //up
        if (dfs(r,c+1,grid,rows,cols)) return true; //right
        if (dfs(r,c-1,grid,rows,cols)) return true; //left
    
        //Return false if none of the 4 directions is clear and drop branch.
        return false;
}

inline bool inBounds(int r, int c, int rows, int cols) {
    //r c is coordinates for where we are working. 
    // rows and cols is the rows and columns of the matrix
    //return false for our path if we ever go out of bounds of matrix
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

} // namespace maze

int main() {// We have two tests, one where path is clear, 
            //one where path isnt. :)
            
    std::vector<std::string> g = {
        "XXXXX",
        "X   X",
        "X   X",
        "X X X",
        "XEXXX"
    };

    bool ok1 = maze::hasPath(g);
    std::cout << "Is there a path to E in maze 1?" << "\n";
    std::cout << std::boolalpha << ok1 << "\n"; // Print TRUE or FALSE

    std::vector<std::string> g2 = {
        "XXXXX",
        "X   X",
        "X   X",
        "XXXXX",
        "XEXXX"
    };

    bool ok2 = maze::hasPath(g2);
    std::cout << "Is there a path to E in maze 2?" << "\n";
    std::cout << std::boolalpha << ok2 << "\n"; // Print TRUE or FALSE

    return 0;
}
