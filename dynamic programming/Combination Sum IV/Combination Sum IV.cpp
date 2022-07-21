class Solution {
public:
    vector <int> ans,step;
    bool* v;
    int combinationSum4(vector<int>& nums, int target) {
        step.assign(nums.begin(),nums.end());
        ans.resize(target+1);
        for(int i = 1 ; i<=target ; i++) ans[i] = 0;
        ans[target] = 1;
        v = new bool[target+1];
        for(int i = 0 ; i<=target ; i++) v[i] = false;
        v[target] = true;
        dfs(0,target);
        return ans[0];
    }
    void dfs(int from,int target)
    {
        for(int i = 0 ; i<step.size() ; i++)
        {
            if(step[i]+from>target) continue;
            if(v[step[i]+from])
            {
                ans[from] += ans[step[i]+from];
                continue;
            }
            dfs(step[i]+from,target);
            ans[from] += ans[step[i]+from];
        }
        v[from] = true;
        return;
    }
};
