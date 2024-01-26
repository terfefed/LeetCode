class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> temp(m, vector<int>(n, 0));

        dp[startRow][startColumn] = 1;
        int result = 0;

        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] > 0) {
                        for (const auto& direction : directions) {
                            int ni = i + direction[0];
                            int nj = j + direction[1];

                            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                                temp[ni][nj] = (temp[ni][nj] + dp[i][j]) % MOD;
                            } else {
                                result = (result + dp[i][j]) % MOD;
                            }
                        }
                    }
                }
            }
            
            dp = temp;
            temp = vector<vector<int>>(m, vector<int>(n, 0));
        }

        return result;
    }
};