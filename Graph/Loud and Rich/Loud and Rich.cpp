class Solution {
public:
    vector < vector <int> > g;
    bool* v;
    vector <int> ans;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        v = new bool[quiet.size()];
        for(int i = 0 ; i<quiet.size() ; i++) v[i] = false;//false->unexplore true->explored
        g.resize(quiet.size());
        ans.resize(quiet.size());
        for(int i = 0; i<richer.size() ; i++)
        {
            g[richer[i][1]].push_back(richer[i][0]);
        }
        for(int i = 0; i<quiet.size() ; i++)
        {
            if(v[i]) continue;
            dfs(i,quiet);
        }
        return ans;
    }
    void dfs(int to,vector <int> quiet)
    {
        v[to] = true;
        int want = to;
        //cout << to << endl;
        for(int i = 0; i<g[to].size() ; i++)
        {
            if(v[g[to][i]])
            {
                if(quiet[want]>quiet[ans[g[to][i]]]) want = ans[g[to][i]];
                continue;
            }
            dfs(g[to][i],quiet);
            if(quiet[want]>quiet[ans[g[to][i]]]) want = ans[g[to][i]];
            //cout << "   " <<g[to][i] << "   " << want << endl;
        }
        ans[to] = want;
    }
};
