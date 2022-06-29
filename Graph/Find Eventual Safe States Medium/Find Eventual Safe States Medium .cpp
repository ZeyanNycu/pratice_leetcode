class Solution {
public:
    vector < vector <int> > g;
    vector <int> ans;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        g.assign(graph.begin(),graph.end());
        char* v = new char [graph.size()];
        for(int i = 0 ; i<graph.size() ; i++) v[i] = 'a'; //'a'->unexplored 'b'->no 'c'->yes
        for(int i = 0 ; i<graph.size() ; i++)   if(v[i] == 'a') dfs(i,v);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void dfs(int src,char* v)
    {
        if(g[src].size() == 0)
        {
            v[src] = 'c';
            ans.push_back(src);
            return;
        }
        v[src] = 'b';
        //cout << src << endl;
        for(int i = 0; i<g[src].size() ; i++)
        {
            if(v[g[src][i]] == 'a') dfs(g[src][i],v);
            if(v[g[src][i]] == 'b') return;
        }
        v[src] = 'c';
        ans.push_back(src);
        return;
    }
};
