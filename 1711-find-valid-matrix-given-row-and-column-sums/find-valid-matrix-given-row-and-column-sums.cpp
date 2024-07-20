#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Determine the value to place in the current cell
                int value = min(rowSum[i], colSum[j]);

                // Place the value in the matrix
                matrix[i][j] = value;

                // Update the row and column sums
                rowSum[i] -= value;
                colSum[j] -= value;

                // If either rowSum[i] or colSum[j] becomes zero, break to the next row or column
                if (rowSum[i] == 0) {
                    break;
                }
                if (colSum[j] == 0) {
                    continue;
                }
            }
        }

        return matrix;
    }
};

