class Solution {
public:
    vector < vector <int> > g,ans;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int cnt = 0;
        g.assign(obstacleGrid.begin(),obstacleGrid.end());
        ans.assign(g.begin(),g.end());
        if(g[0][0] == 0)
        {
            if(g.size() == 1 && g[0].size() == 1) return 1;
            g[0][0] = 2;
            if(g[0].size()>1)
            {
                if(g[0][1]!=1) cnt += dfs(0,1);
            }
            if(g.size()>1) 
            {
                if(g[1][0] == 2)
                {
                    cnt += ans[1][0];
                }
                else if(g[1][0] == 0)
                {
                    cnt += dfs(1,0);
                }

            }
        }
        return cnt;
    }
    int dfs(int x,int y)
    {
        int cnt = 0;
        if(x == g.size()-1 && y == g[0].size()-1) return 1;
        g[x][y] = 1;
        if(x+1<g.size())
        {
            if(g[x+1][y] == 2)  cnt += ans[x+1][y];
            else if (g[x+1][y] ==0) cnt += dfs(x+1,y);
        }
        if(y+1<g[0].size())
        {
            if(g[x][y+1] == 2) cnt +=ans[x][y+1];
            else if (g[x][y+1] == 0) cnt += dfs(x,y+1);
        }
        ans[x][y] = cnt;
        g[x][y] = 2;
        return cnt;
    }
};
