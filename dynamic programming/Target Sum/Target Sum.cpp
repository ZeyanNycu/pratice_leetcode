class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector < map<int,int> > ans(nums.size());
        ans[0][nums[0]]++; 
        ans[0][nums[0]*(-1)]++;
        for(int i = 1; i<nums.size() ; i++)
        {
            for(auto it:ans[i-1])
            {
                if( ans[i].count(it.first+nums[i]) == 0) ans[i][it.first+nums[i]] = 0;
                if( ans[i].count(it.first-nums[i]) == 0) ans[i][it.first-nums[i]] = 0;
                ans[i][it.first+nums[i]] += ans[i-1][it.first];
                ans[i][it.first-nums[i]] += ans[i-1][it.first];
            }
        }
        if(ans[nums.size()-1].count(target))   return ans[nums.size()-1][target];
        return 0;
    }
};
