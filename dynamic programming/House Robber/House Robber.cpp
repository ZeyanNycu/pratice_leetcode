class Solution {
public:
    int rob(vector<int>& nums) {
        vector < int > v;
        int ans = nums[0];
        v.resize(nums.size());
        v[0] = nums[0];
        if(v.size()>1)
        {
            v[1] = nums[1];
            ans = max(v[1],ans);
            for(int i = 2; i<nums.size() ; i++)
            {
                v[i] = nums[i];
                for(int j = 0 ; j<i-1 ; j++)  v[i] = max(v[j]+nums[i],v[i]);
                int temp = max(v[i],v[i-1]);
                ans = max(ans,temp);
            }
        }
        //for(auto it: v) cout << it << " ";
        return ans;
    }
};
