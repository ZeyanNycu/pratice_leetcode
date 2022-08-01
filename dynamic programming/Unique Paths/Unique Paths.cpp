class Solution {
public:
    vector < vector <int> > dp;
    bool** v;
    int uniquePaths(int m, int n) {
        v = new bool* [m];
        dp.resize(m);
        for(int i = 0 ; i<m ; i++)
        {
            v[i] = new bool [n];
            dp[i].resize(n);
        }
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                v[i][j] = false;
                dp[i][j] = 0;
            }
        }
        v[m-1][n-1] = true;
        dp[m-1][n-1] = 1;
        return dfs(0,0);
    }
    int dfs(int from_i,int from_j)
    {
        if(from_i == dp.size()-1 && from_j == dp[0].size()-1) return 1;
        if(from_i+1<dp.size())
        {
            if(v[from_i+1][from_j]) dp[from_i][from_j] += dp[from_i+1][from_j];
            else    dp[from_i][from_j] += dfs(from_i+1,from_j);
        }
        if(from_j+1<dp[0].size())
        {
            if(v[from_i][from_j+1]) dp[from_i][from_j] += dp[from_i][from_j+1];
            else    dp[from_i][from_j] += dfs(from_i,from_j+1);
        }
        v[from_i][from_j] = true;
        return dp[from_i][from_j];
    }
};
