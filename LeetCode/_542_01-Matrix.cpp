/*
https://leetcode.com/problems/01-matrix/

Time Complexity: O(rows*cols)
Space Complexity: O(rows*cols)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<int>> newMatrix(rows, std::vector<int>(cols, 100));
        std::queue<std::pair<int, int>> cells;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    newMatrix[i][j] = 0;
                    cells.push({i, j});
                }
            }
        }
        
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!cells.empty()) {
            std::pair<int, int> current = cells.front();
            cells.pop();

            for (int i = 0; i < 4; i++) {
                int x = current.first + dir[i][0];
                int y = current.second + dir[i][1];
                if (x >= 0 && y >= 0 && x < rows && y < cols) {
                    if(newMatrix[x][y] > newMatrix[current.first][current.second] + 1) {
                        newMatrix[x][y] = newMatrix[current.first][current.second] + 1;
                        cells.push({x, y});
                    }
                }

            }
        }
        
        return newMatrix;
    }
};