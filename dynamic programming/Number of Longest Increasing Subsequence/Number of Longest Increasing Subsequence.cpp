class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector  < pair<int,int> >dp( nums.size() );
        dp[0] = make_pair(1,1);
        for(int i = 1 ; i<nums.size() ; i++)
        {
            int len = 1;
            int num = 1;
            for(int j = 0 ; j<i ; j++)
            {
                if(nums[i]>nums[j])
                {
                    if(len<dp[j].first+1)
                    {
                        len = dp[j].first+1;
                        num = dp[j].second;
                    }
                    else if(len == dp[j].first+1) num+=dp[j].second;
                }
            }
            dp[i] = make_pair(len,num);
        }
        //for(auto it:dp) cout << it.first << " " << it.second << endl;
        int len = dp[0].first;
        int cnt = dp[0].second;
        for(int i = 1 ; i<dp.size() ; i++)
        {
            if(dp[i].first>len)
            {
                cnt = dp[i].second;
                len = dp[i].first;
            }
            else if(dp[i].first == len) cnt+=dp[i].second;
        }
        return cnt;
    }
};
