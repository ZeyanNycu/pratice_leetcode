class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector < vector <int> > dp1(nums.size());
        vector < vector <int> > dp2(nums.size());
        dp1[0].push_back(nums[0]); dp2[0].push_back(nums[0]);
        for(int i = 1; i<nums.size() ; i++)
        {
            int len1 = 0,len2 = 0; 
            int ind1 = -1,ind2 = -1;
            for(int j = 0 ; j<i ; j++)
            {
                if(nums[i]>nums[j])
                {
                    if(len1<dp2[j].size())
                    {
                        len1 = dp2[j].size();
                        ind1 = j;
                    }
                }
                if(nums[i]<nums[j])
                {
                    if(len2<dp1[j].size())
                    {
                        len2 = dp1[j].size();
                        ind2 = j;
                    }
                }
            }
            if(ind1 != -1) dp1[i].assign(dp2[ind1].begin(),dp2[ind1].end());
            if(ind2 != -1) dp2[i].assign(dp1[ind2].begin(),dp1[ind2].end());
            dp1[i].push_back(nums[i]);
            dp2[i].push_back(nums[i]);
        }
        int ans = dp1[0].size();
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(ans<dp1[i].size()) ans = dp1[i].size();
            if(ans<dp2[i].size()) ans = dp2[i].size();
        }
        return ans;
    }
};
