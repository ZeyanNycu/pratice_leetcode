class Solution {
public:
    vector < vector < vector <long long> > > dis;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return 0;
        dis.resize(maxMove);
        for(int j = 0 ; j<maxMove ; j++)
        {
            dis[j].resize(m);
            for(int k = 0 ; k<m ; k++)
            {
                dis[j][k].resize(n);
            }
        }
        for(int j = 0 ; j<m ; j++)
        {
            for(int k = 0 ; k<n ; k++)
            {
                dis[0][j][k] = 0;
                if(m-1 == 0) dis[0][j][k]+=2;
                else if(j==0 || j==m-1) dis[0][j][k]++;
                
            }
            dis[0][j][0]++;
            dis[0][j][n-1]++;
        }
        for(int i = 1; i<maxMove ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                for(int k = 0 ; k<n ; k++)
                {
                    if(j-1>=0) dis[i][j][k] += dis[i-1][j-1][k] % 1000000007;
                    if(k-1>=0) dis[i][j][k] += dis[i-1][j][k-1] % 1000000007;
                    if(j+1<m) dis[i][j][k] += dis[i-1][j+1][k] % 1000000007;
                    if(k+1<n) dis[i][j][k] += dis[i-1][j][k+1] % 1000000007;
                }
            }
        }
        long long ans = 0;
        for(auto it:dis)    ans = (ans+it[startRow][startColumn])%1000000007;
        return ans;
    }
};
