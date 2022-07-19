class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector < set <int> > dp;
        dp.resize(nums.size());
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size() ; i++) dp[i].insert(nums[i]);
        for(int i = 1 ; i<nums.size() ; i++)
        {
            bool sign = true;
            int big,ind;
            for(int j = 0; j<i ; j++)
            {
                int a = nums[i],b = nums[j];
                if(a%b ==0) 
                {
                    if(sign || big<dp[j].size())
                    {
                        if(sign)    sign = false;  
                        big = dp[j].size();
                        ind = j;
                    }
                }
            }
            if(!sign)    dp[i].insert(dp[ind].begin(),dp[ind].end());
        }
        int ind = 0,big = dp[0].size();
        for(int i = 1; i<nums.size() ; i++)
        {
            if(big<dp[i].size())
            {
                big = dp[i].size();
                ind = i;
            }
        }
        vector <int> ans;
        for(auto it:dp[ind]) ans.push_back(it);
        return ans;
    }
};
