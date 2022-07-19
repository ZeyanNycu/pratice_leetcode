class Solution {
public:
    int getMoneyAmount(int n) {
        vector < vector <int> > dp;
        dp.resize(n+1);
        for(int i = 1; i<dp.size() ; i++) dp[i].resize(n+1);
        for(int i = 1; i<dp.size() ; i++) dp[i][i] = 0;
        for(int j = 2; j<dp.size() ; j++)
        {
            for(int i=j-1 ; i>=1 ; i--)
            {
                int num = dp[i+1][j]+i;
                for(int k = i+1; k<j ; k++)
                { 
                    int temp = max(dp[i][k-1],dp[k+1][j]);
                    num = min(num,temp+(k));
                }
                dp[i][j] = num;
            }
        }
        return dp[1][n];
    }
};
