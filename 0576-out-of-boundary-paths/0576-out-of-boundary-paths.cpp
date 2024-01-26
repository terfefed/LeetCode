class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        unordered_map<long long, int> memo;

        return dfs(m, n, maxMove, startRow, startColumn, memo, MOD);
    }

private:
    int dfs(int m, int n, int maxMove, int i, int j, unordered_map<long long, int>& memo, const int MOD) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;  // Out of boundary
        }

        if (maxMove == 0) {
            return 0;  // No more moves allowed
        }

        long long key = ((long long)i << 32) | ((long long)j << 16) | maxMove;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int result = 0;

        for (const auto& direction : directions) {
            int ni = i + direction.first;
            int nj = j + direction.second;

            result = (result + dfs(m, n, maxMove - 1, ni, nj, memo, MOD)) % MOD;
        }

        memo[key] = result;
        return result;
    }
};