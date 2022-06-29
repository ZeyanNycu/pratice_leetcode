class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector < vector < vector <int> > > path;
        char* v = new char [graph.size()];
        path.resize(graph.size());
        for(int i = 0; i<graph.size() ; i++) v[i] = 'a'; // a->not visited  b->失敗 c->成功並記錄路徑
        v[graph.size()-1] = 'c';
        vector <int> temp;
        temp.push_back(graph.size()-1);
        path[graph.size()-1].push_back(temp);
        dfs(0,v,graph,path);
        return path[0];
    }
    void dfs(int src,char* v, vector < vector <int> > g, vector < vector < vector <int> > >& path)
    {
        v[src] = 'b';
        for(int i = 0 ; i<g[src].size() ; i++)
        {
            if(v[g[src][i]] == 'b') continue;
            if(v[g[src][i]] == 'c')
            {
                v[src] = 'c';
                for(int j = 0; j < path[g[src][i]].size() ; j++)
                {
                    vector <int> temp;
                    temp.assign(path[g[src][i]][j].begin(),path[g[src][i]][j].end());
                    temp.insert(temp.begin(),src);
                    path[src].push_back(temp);
                }
                continue;
            }
            dfs(g[src][i],v,g,path);
            if(v[g[src][i]] == 'c')
            {
                v[src] = 'c';
                for(int j = 0; j < path[g[src][i]].size() ; j++)
                {
                    vector <int> temp;
                    temp.assign(path[g[src][i]][j].begin(),path[g[src][i]][j].end());
                    temp.insert(temp.begin(),src);
                    path[src].push_back(temp);
                }
                continue;
            }
        }
        return;
    }
};
