class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a,pair<int, int> b) {
            return a.second > b.second;
        }
    };
    vector <long long> ans,dfs_ans;
    vector < vector < pair<int,int> > > g;
    bool* v;
    long long cnt = 0;
    char* dfs_v;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        v = new bool [n+1];
        dfs_v = new char [n+1];
        g.resize(n+1); ans.resize(n+1); dfs_ans.resize(n+1);
        for(int i =0 ; i<n+1 ; i++) v[i] = false;
        for(int i = 0 ; i<edges.size() ; i++)
        {
            g[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            g[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
        }
        priority_queue < pair<int,int> , vector< pair<int,int> >, cmp  >bfs;
        bfs.push(make_pair(n,0));
        ans[n] = 0;
        v[n] = true;
        while(bfs.size())
        {
            int top = bfs.top().first;
            int dis = bfs.top().second;
            bfs.pop();
            //cout << top  << " " << dis << endl;
            for(int i = 0 ; i<g[top].size() ; i++)
            {
                if(v[g[top][i].first] && ans[g[top][i].first]<=dis+g[top][i].second) continue;
                int temp =  dis+g[top][i].second;
                bfs.push(make_pair(g[top][i].first, temp));
                ans[g[top][i].first] = temp;
                v[g[top][i].first] = true;
            }
        }
        //for(auto it : ans) cout << it << " ";
        //cout << endl;
        for(int i = 0; i<n ; i++) dfs_v[i] = 'a'; // 'a'->unexplored 'b'->exploring 'c'->explored
        dfs_v[1] = 'b';
        for(int i = 0; i<g[1].size() ; i++)
        {
            if(ans[g[1][i].first]>=ans[1]) continue;
            if(dfs_v[g[1][i].first] == 'b') continue;
            if(dfs_v[g[1][i].first] == 'c')
            {
                cnt += dfs_ans[g[1][i].first];  
                cnt %= 1000000007;
                continue;
            }
            cnt += dfs(g[1][i].first);
            cnt %= 1000000007;
        }
        return cnt;
    }
    long long dfs(int to)
    {
        if(to == g.size()-1) return 1;
        long long want = 0;
        dfs_v[to] = 'b';
        //cout << to << endl;
        for(int i = 0; i<g[to].size() ; i++)
        {
            if(ans[g[to][i].first]>=ans[to]) continue;
            if(dfs_v[g[to][i].first] == 'b') continue;
            if(dfs_v[g[to][i].first] == 'c')
            {
                want += dfs_ans[g[to][i].first];
                //want %= 1000000007;
                continue;
            }
            want += dfs(g[to][i].first);
            want %= 1000000007;
            //cout << want << endl;
        }
        dfs_v[to] = 'c';
        dfs_ans[to] = want%1000000007;
        return want;
    }
};
