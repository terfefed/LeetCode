class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp1(m, vector<int>(n, 0));
        vector<vector<int>> dp2(m, vector<int>(n, 0));

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int move = 1; move <= maxMove; ++move) {
            vector<vector<int>>& current = (move % 2 == 1) ? dp1 : dp2;
            vector<vector<int>>& previous = (move % 2 == 0) ? dp1 : dp2;

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    current[i][j] = 0;  // Reset the current value

                    for (const auto& direction : directions) {
                        int ni = i + direction.first;
                        int nj = j + direction.second;

                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            current[i][j] = (current[i][j] + 1) % MOD;
                        } else {
                            current[i][j] = (current[i][j] + previous[ni][nj]) % MOD;
                        }
                    }
                }
            }
        }

        return (maxMove % 2 == 1) ? dp1[startRow][startColumn] : dp2[startRow][startColumn];
    }
};