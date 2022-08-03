class Solution {
public:
    int numTilings(int n) {
        int dp [2][n];
        for(int i = 0 ; i<2 ; i++)
        {
            for(int j = 0 ; j<n ; j++) dp[i][j] = 0;
        }
        dp[0][0] = 0;
        dp[1][0] = 1;
        if(n == 1) return dp[1][0];
        dp[0][1] = 1;
        dp[1][1] = 2;
        if(n>2)
        {
            dp[0][2] = 2;
            dp[1][2] = 5;
            if(n>3)
            {
               for(int j = 3 ; j<n ; j++)
               {
                    for(int i = 0 ; i<2 ; i++)
                    {
                        if(i==0)
                        {
                            dp[i][j] += (dp[1][j-2]);
                            dp[i][j] %= 1000000007;
                            dp[i][j] += dp[0][j-2];
                            dp[i][j] %= 1000000007;
                            dp[i][j] += dp[1][j-3];
                            dp[i][j] %= 1000000007;
                        }
                        else
                        {
                            dp[i][j] += dp[1][j-1]; 
                            dp[i][j] %= 1000000007;
                            dp[i][j] += dp[0][j-1];
                            dp[i][j] %= 1000000007;
                            dp[i][j] += dp[1][j-2];
                            dp[i][j] %= 1000000007;
                            dp[i][j] += dp[0][j-2];
                            dp[i][j] %= 1000000007;
                            dp[i][j] += dp[1][j-3];
                            dp[i][j] %= 1000000007;
                        }
                    } 
               }
            }
        }
        return dp[1][n-1];
    }
};
