class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (const auto& direction : directions) {
                        int ni = i + direction.first;
                        int nj = j + direction.second;

                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            dp[i][j][move] = (dp[i][j][move] + dp[ni][nj][move - 1]) % MOD;
                        } else {
                            dp[i][j][move] = (dp[i][j][move] + 1) % MOD;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};