class Solution {
public:
    vector <int> ans;
    vector < vector<int> > rg;
    vector < vector<int> > bg;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        rg.resize(n);bg.resize(n);ans.resize(n);
        bool* rv = new bool [n];
        bool* bv = new bool [n];
        for(int i = 0 ; i<n ; i++)
        {
            rv[i] = false;
            bv[i] = false;
            ans[i] = -1;
        }
        for(int i = 0; i<redEdges.size() ; i++) rg[redEdges[i][0]].push_back(redEdges[i][1]);
        for(int i = 0 ; i<blueEdges.size() ; i++) bg[blueEdges[i][0]].push_back(blueEdges[i][1]);
        queue < pair<int,bool> > bfs;
        queue <int> dis;
        bfs.push(make_pair(0,true)); //true 代表 red false 代表 blue
        bfs.push(make_pair(0,false));
        rv[0] = true; bv[0] = true; 
        ans[0] = 0; dis.push(0); dis.push(0);
        while(bfs.size())
        {
            int top = bfs.front().first;
            bool sign = bfs.front().second;
            int step = dis.front();
            step++;
            bfs.pop(); dis.pop();
            //cout << top << " " << step << endl;
            if(sign)
            {
                for(int i = 0; i<bg[top].size() ; i++)
                {
                    if(bv[bg[top][i]]) continue;
                    bv[bg[top][i]] = true;
                    if(step<ans[bg[top][i]] || ans[bg[top][i]] == -1) ans[bg[top][i]] = step;
                    dis.push(step);
                    bfs.push(make_pair(bg[top][i],false));
                }
            }
            else
            {
                for(int i = 0; i<rg[top].size() ; i++)
                {
                    if(rv[rg[top][i]]) continue;
                    rv[rg[top][i]] = true;
                    if(step<ans[rg[top][i]] || ans[rg[top][i]] == -1) ans[rg[top][i]] = step;
                    dis.push(step);
                    bfs.push(make_pair(rg[top][i],true));
                }
            }
        }
        return ans;
    }
};
