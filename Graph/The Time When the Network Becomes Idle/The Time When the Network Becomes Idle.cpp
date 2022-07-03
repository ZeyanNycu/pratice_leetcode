class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        vector < vector <int> > g;
        vector <int> dis;
        g.resize(patience.size()); dis.resize(patience.size());
        for(int i = 0 ; i<edges.size() ; i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        bool* v = new bool [g.size()];
        for(int i = 0 ; i<g.size() ; i++) v[i] = false;
        queue <int> bfs;
        bfs.push(0); v[0] = true; dis[0] = 0;
        while(bfs.size())
        {
            int top = bfs.front();
            bfs.pop();
            for(int i = 0 ; i<g[top].size() ; i++)
            {
                if(v[g[top][i]]) continue;
                bfs.push(g[top][i]);
                v[g[top][i]] = true;
                dis[g[top][i]] = dis[top]+1;
            }
        }
        int ans = 0;
        for(int i =1; i<g.size() ; i++)
        {
            int temp = ((dis[i]*2-1)/patience[i]);
            temp *= patience[i];
            temp += 2*dis[i]; temp++;
            ans = max(ans,temp);
        }
        return ans;
    }
};
