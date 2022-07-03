class Solution {
public:
    vector < vector < pair<int,int> > > g;
    vector <long long> dis;
    vector <long long> dfs_dis;
    char* dfs_v;
    int countPaths(int n, vector<vector<int>>& roads) {
        if(roads.size() == 0) return 1;
        g.resize(n); dis.resize(n); dfs_dis.resize(n);
        bool* v = new bool [n];
        dfs_v = new char [n];
        for(int i = 0 ; i<n ; i++)
        {
            v[i] = false;
            dfs_v[i] =  'a';
        }
        for(int i = 0 ; i<roads.size() ; i++)
        {
            g[roads[i][0]].push_back(make_pair(roads[i][1],roads[i][2]));
            g[roads[i][1]].push_back(make_pair(roads[i][0],roads[i][2]));
        }
        priority_queue < pair<long long,int>, vector < pair<long long,int> > , greater< pair<long long,int> > > bfs;
        v[0] = true;
        bfs.push(make_pair(0,0));
        while(bfs.size())
        {
            long long d = bfs.top().first;
            int top = bfs.top().second;
            bfs.pop();
            for(int i = 0; i<g[top].size() ; i++)
            {
                long long tmp = d + g[top][i].second;
                if(v[g[top][i].first] && dis[g[top][i].first]<=tmp) continue;
                v[g[top][i].first] = true;
                bfs.push(make_pair(tmp,g[top][i].first));
                dis[g[top][i].first] = tmp;
            }
        }
        //for(auto it:dis) cout << it << " ";
        //cout << endl;
        int cnt = 0;
        dfs_v[0] = 'b';
        for(int i = 0 ; i<g[0].size() ; i++)
        {
            if(dis[g[0][i].first] != g[0][i].second) continue;
            if(dfs_v[g[0][i].first] == 'b') continue;
            if(dfs_v[g[0][i].first] == 'c')
            {
                cnt += dfs_dis[g[0][i].first];
                cnt %= 1000000007;
                continue;
            }
            cnt += dfs(g[0][i].first);
            //cout << cnt << endl;
            cnt %= 1000000007;
            //cout << endl;
        }
        //for (auto it:dfs_dis) cout << it << " ";
        //cout << endl;
        return cnt;
    }
    int dfs(int to)
    {
        //cout << to << " ";
        if(to == g.size()-1) return 1;
        int cnt = 0;
        dfs_v[to] = 'b';
        for(int i = 0; i<g[to].size() ; i++)
        {
            if(dis[g[to][i].first] != g[to][i].second+dis[to]) continue;
            if( dfs_v[g[to][i].first] == 'b' || dis[to]+g[to][i].second>dis[g.size()-1]) continue;
            if(dfs_v[g[to][i].first] == 'c')
            {
                cnt += dfs_dis[g[to][i].first];
                cnt %= 1000000007;
                continue;
            }
            cnt += dfs(g[to][i].first);
            cnt %= 1000000007;
        }
        //cout << to << " " << cnt << endl;
        dfs_dis[to] = cnt;
        dfs_v[to] = 'c';
        return cnt;
    }
};
