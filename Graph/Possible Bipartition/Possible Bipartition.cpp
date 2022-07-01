class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector < vector <int> > g;
        g.resize(n+1);
        for(int i = 0; i<dislikes.size() ; i++)
        {
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        set <int> A;
        set <int> B;
        for(int i = 1; i<=n ; i++)
        {
            if(A.count(i) || B.count(i)) continue;
            queue < pair<int,bool> > bfs;
            bfs.push(make_pair(i,true));
            A.insert(i);
            while(bfs.size())
            {
                int top = bfs.front().first;
                bool sign = bfs.front().second;
                //cout << top << endl;
                bfs.pop();
                for(int j = 0 ; j<g[top].size() ; j++)
                {
                    if(sign)
                    {
                        if(A.count(g[top][j])) return false;
                        if(B.count(g[top][j])) continue;
                        bfs.push(make_pair(g[top][j],!sign));
                        B.insert(g[top][j]);
                    }
                    else
                    {
                        if(A.count(g[top][j])) continue;
                        if(B.count(g[top][j]))  return false;
                        bfs.push(make_pair(g[top][j],!sign));
                        A.insert(g[top][j]);
                    }
                }
            }
        }
        return true;
    }
};
