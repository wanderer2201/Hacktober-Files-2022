class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        
        # create a dp array of size m * n to store already computed max_increasing_path_length for index (i, j)
        # where 0 <= i < m and 0 <= j < n
        # initialize the dp array by -1 as length of path can only be a whole number. 
        dp = [[-1] * n for _ in range(m)]
        
        def dfs(i, j, prev):
            if i < 0 or j < 0 or i >= m or j >= n or matrix[i][j] <= prev:
                return 0
            
            # if dp[i][j] != -1, that means dp[i][j] has been updated by some >= 0 path length.
            # hence directly use it without recomputing and save recursion time and space.
            if dp[i][j] != -1:
                return dp[i][j]
            
            # compute if dp[i][j] = -1 meaning (i, j) still not computed
            left = dfs(i, j - 1, matrix[i][j])
            right = dfs(i, j + 1, matrix[i][j])
            top = dfs(i - 1, j, matrix[i][j])
            bottom = dfs(i + 1, j, matrix[i][j])
            
            # update the dp value after computing path length for index (i , j)
            # so that we can use it next time without recomputation.
            dp[i][j] = max(left, right, top, bottom) + 1
            return dp[i][j]
        
        ans = -1
        for i in range(m):
            for j in range(n):
                ans = max(ans, dfs(i, j, -1))
        return ans
