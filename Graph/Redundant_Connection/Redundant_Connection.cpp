class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector <int> jud;
        vector <int> rank;
        vector <int> ans;
        for(int i = 0 ; i<1001 ; i++)
        {
            jud.push_back(i);
            rank.push_back(1);
        }
        for(int i = 0 ; i<edges.size() ; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            if(isset(a,b,jud,rank)) continue;
            ans.push_back(edges[i][0]);
            ans.push_back(edges[i][1]);
        }
        return ans;
    }
    bool isset(int a,int b, vector <int>& jud,vector <int>& rank)
    {
        if(jud[a] != a) a = find_value(a,jud);
        if(jud[b] != b) b = find_value(b,jud);
        if(a==b) return false;
        if(rank[a]>=rank[b])
        {
            jud[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
        else jud[a] = b;
        return true;
    }
    int find_value(int a,vector <int> &jud)
    {
        if(jud[a] == a) return a;
        jud[a] = find_value(jud[a],jud);
        return jud[a];
    }
};
