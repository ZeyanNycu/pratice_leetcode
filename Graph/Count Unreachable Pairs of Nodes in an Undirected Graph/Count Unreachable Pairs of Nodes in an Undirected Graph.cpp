class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector < vector <int> > g;
        long long num = 0;
        long long ans = 0;
        g.resize(n);
        for(int i = 0; i<edges.size() ; i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        bool * v = new bool[n];
        for(int i = 0; i<n ; i++) v[i] = false;
        for(int i = 0; i<n ; i++)
        {
            if(v[i]) continue;
            v[i] = true;
            queue<int> bfs;
            bfs.push(i);
            int cnt = 1;
            while(bfs.size())
            {
                int top = bfs.front();
                bfs.pop();
                for(int j = 0 ; j<g[top].size() ; j++)
                {
                    if(v[g[top][j]]) continue;
                    bfs.push(g[top][j]);
                    v[g[top][j]] = true;
                    cnt++;
                }
            }
            ans += num*cnt;
            num += cnt;
        }
        return ans;
    }
};
