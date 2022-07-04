class Solution {
public:
    vector < vector <int> > g;bool* record;
    bool jud(int i,int j)
    {
        long long x = (g[i][0]-g[j][0]);
        x*=x;
        long long y = (g[i][1] - g[j][1]);
        y*=y;
        long long r = (g[i][2]);
        r *=r;
        if(r<x+y) return true;
        return false;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        g.assign(bombs.begin(),bombs.end());
        int ans = 1;
        for(int i = 0; i<bombs.size() ; i++)
        {
            record = new bool [bombs.size()];
            for(int j = 0; j<bombs.size() ; j++) record[j] = false;
            record[i] = true;
            int cnt = 1;
            for(int j = 0 ; j<bombs.size() ; j++)
            {
                if(jud(i,j)) continue;
                if(record[j]) continue;
                cnt += dfs(j);
            }
            ans = max(cnt,ans);
        } 
        return ans;
    }
    int dfs(int to)
    {
        int cnt = 1;
        record[to] = true;
        //cout << to << endl;
        for(int i = 0;i<g.size() ; i++)
        {
            if(jud(to,i)) continue;
            if(record[i]) continue;
            cnt += dfs(i);
        }
        return cnt;
    }
};
