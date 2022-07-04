class Solution {
public:
    vector < vector <int> > g;
    bool* v;
    vector < set <int> > ans;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        v = new bool [n];
        ans.resize(n); g.resize(n);
        for(int i = 0 ; i<n ; i++) v[i] = false;
        for(int i = 0 ; i<edges.size() ; i++)   g[edges[i][1]].push_back(edges[i][0]);
        for(int i = 0 ; i<n ; i++)
        {
            if(v[i]) continue;
            for(int j = 0 ; j<g[i].size() ; j++)
            {
                ans[i].insert(g[i][j]);
                if(v[g[i][j]])
                {
                    for(auto it: ans[g[i][j]])  ans[i].insert(it);
                    continue;
                }
                dfs(g[i][j]);
                for(auto it: ans[g[i][j]])  ans[i].insert(it);
            }
            v[i] = true;
        }
        vector < vector <int> > want;
        want.resize(n);
        for(int i = 0 ; i<n ; i++)
        {
            for(auto it:ans[i]) want[i].push_back(it);
        }
        return want;
    }
    void dfs(int to)
    {
        for(int i = 0; i<g[to].size() ; i++)
        {
            ans[to].insert(g[to][i]);
            if(v[g[to][i]])
            {
                for(auto it: ans[g[to][i]])  ans[to].insert(it);
                continue;
            }
            dfs(g[to][i]);
            for(auto it: ans[g[to][i]])  ans[to].insert(it);
        }
        v[to] = true;
    }
};
