class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // 每找到一個0就開始bfs，比較小的要重用
        vector < vector <int> > ans( mat.size(),vector <int> (mat[0].size()) );
        vector < vector <bool> > v( mat.size(),vector <bool> (mat[0].size(),false) );
        for(int i = 0 ; i<mat.size() ; i++)
        {
            for(int j = 0; j<mat[i].size() ; j++)
            {
                if(mat[i][j] != 0) continue;
                ans[i][j] = 0;
                v[i][j] = true;
                queue <int> bfs_i,bfs_j;
                bfs_i.push(i); bfs_j.push(j);
                while(bfs_i.size())
                {
                    int top_i = bfs_i.front();
                    int top_j = bfs_j.front();
                    bfs_i.pop(); bfs_j.pop();
                    if(top_i-1>=0 && (!v[top_i-1][top_j] || ans[top_i][top_j]+1<ans[top_i-1][top_j]))
                    {
                        v[top_i-1][top_j] = true;
                        if(mat[top_i-1][top_j] == 0) ans[top_i-1][top_j] = 0;
                        else ans[top_i-1][top_j] = ans[top_i][top_j]+1;
                        bfs_i.push(top_i-1);
                        bfs_j.push(top_j);
                    }
                    if(top_j-1>=0 && (!v[top_i][top_j-1] || ans[top_i][top_j]+1<ans[top_i][top_j-1]))
                    {
                        v[top_i][top_j-1] = true;
                        if(mat[top_i][top_j-1] == 0) ans[top_i][top_j-1] = 0;
                        else ans[top_i][top_j-1] = ans[top_i][top_j]+1;
                        bfs_i.push(top_i);
                        bfs_j.push(top_j-1);
                    }
                    if(top_i+1<mat.size() && (!v[top_i+1][top_j] || ans[top_i][top_j]+1<ans[top_i+1][top_j]))
                    {
                        v[top_i+1][top_j] = true;
                        if(mat[top_i+1][top_j] == 0) ans[top_i+1][top_j] = 0; 
                        else ans[top_i+1][top_j] = ans[top_i][top_j]+1;
                        bfs_i.push(top_i+1);
                        bfs_j.push(top_j);
                    }
                    if(top_j+1<mat[i].size() && (!v[top_i][top_j+1] || ans[top_i][top_j]+1<ans[top_i][top_j+1]))
                    {
                        v[top_i][top_j+1] = true;
                        if(mat[top_i][top_j+1] == 0) ans[top_i][top_j+1] = 0;
                        else ans[top_i][top_j+1] = ans[top_i][top_j]+1;
                        bfs_i.push(top_i);
                        bfs_j.push(top_j+1);
                    }
                }
            }
        }
        return ans;
    }
};
