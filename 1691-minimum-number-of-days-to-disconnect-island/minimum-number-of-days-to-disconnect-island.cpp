class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // DFS function to explore the island
        function<void(int, int, vector<vector<int>>&, vector<vector<bool>>&)> dfs = [&](int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
            if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0 || visited[row][col]) 
                return;
            visited[row][col] = true;
            dfs(row - 1, col, grid, visited);
            dfs(row + 1, col, grid, visited);
            dfs(row, col - 1, grid, visited);
            dfs(row, col + 1, grid, visited);
        };

        // Function to count the number of islands
        auto count_islands = [&]() -> int {
            int count = 0;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        dfs(i, j, grid, visited);
                        ++count;
                    }
                }
            }
            return count;
        };

        // Step 1: Check if the grid is already disconnected
        if (count_islands() != 1) {
            return 0;
        }

        // Step 2: Check if removing one land cell disconnects the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  // Remove the land cell
                    if (count_islands() != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;  // Revert the change
                }
            }
        }

        // If neither of the above steps work, it takes at least 2 days
        return 2;
    }
};
