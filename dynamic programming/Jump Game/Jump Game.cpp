class Solution {
public:
    vector <int> g;
    bool* v;
    bool canJump(vector<int>& nums) {
        v = new bool [nums.size()];
        g.assign(nums.begin(),nums.end());
        for(int i = 0 ; i<nums.size() ; i++) v[i] = false;
        v[0] = true;
        for(int j = 1 ; j<=nums[0] ; j++)
        {
            if(0+j>=nums.size()) continue;
            if(v[0+j]) continue;
            if(dfs(0+j)) return true;
        }
        return v[g.size()-1];
    }
    bool dfs(int to)
    {
        v[to] = true;
        if(to == g.size()-1) return true;
        for(int i = 1 ; i<=g[to] ; i++)
        {
            if(to+i>=g.size()) continue;
            if(v[to+i]) continue;
            if(dfs(to+i)) return true;
        }
        return false;
    }
};
