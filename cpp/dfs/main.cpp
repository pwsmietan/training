/*
* Abstract: Daniel/Paul discussion on leet code problem. 
*
* I had to look up DFS on Wiki and found a nice psuedo code explanation so implemented in C++. 
* I don't *love* the inner/outer loop; there must be a cleaner array-based way to solve (APL comes to mind - more on that later). 
* In the meantime, Daniel, take a peek at this code for giggles. I'm sure you can improve it!
*
* PWS   24 MAY 2024     Initial creation.
*/
#include <iostream>
#include <vector>

class IslandClass
{
public:
    IslandClass()
    {
        // NOP
    };

    ~IslandClass()
    {
        std::cout << "Destructor Invoked - Free Memory Object\n";
    };

    int CalculateNumberOfIslands(std::vector<std::vector<char>>& grid)
    {
        // Abort if our grid is empty!
        if(grid.empty())
            return 0;

        // Initialize working vars:
        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Traverse 2D grid and call DFS function:
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    numIslands++;
                    DepthFirstSearch(grid, i, j);
                }
            }
        }

        return numIslands;
    }

    /// @brief Depth-first search (DFS): Nice write-up on WikiPedia: https://en.wikipedia.org/wiki/Depth-first_search
    /// @param grid (pass by reference faster than by value)
    /// @param i 
    /// @param j 
    void DepthFirstSearch(std::vector<std::vector<char>>& grid, int i, int j)
    {
        // Grab boundary segments:
        int rows = grid.size();
        int cols = grid[0].size();

        // Check boundaries: bail out if out of bounds or already visited:
        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0')
            return;

        // Mark the cell as visited:
        grid[i][j] = '0';

        /*
        * Recursively inspect adjacent cells on current and previous/next rows:
        * [i+1], [i-1], [j+1], [j-1].
        */
        DepthFirstSearch(grid, i + 1, j);
        DepthFirstSearch(grid, i - 1, j);
        DepthFirstSearch(grid, i, j + 1);
        DepthFirstSearch(grid, i, j - 1);
    }
};

int main(int argc, char* argv[])
{
    /*
    * Our 2D Island Grid where 1' are land and 0's are water.
    * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    * You may assume all four edges of the grid are all surrounded by water.
    */
    std::vector<std::vector<char>> threeIslandGrid = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}
    };

    std::vector<std::vector<char>> oneIslandGrid = {
         {'1','1','1','1','0'},
         {'1','1','0','1','0'},
         {'1','1','0','0','0'},
         {'0','0','0','0','0'}
    };

    // Instantiate our class and invoke method call:
    IslandClass islandObj;
    std::cout << "Three Island Grid: ";
    std::cout << islandObj.CalculateNumberOfIslands(threeIslandGrid) << std::endl;

    std::cout << "One Island Grid: ";
    std::cout << islandObj.CalculateNumberOfIslands(oneIslandGrid) << std::endl;

    return 0;
}