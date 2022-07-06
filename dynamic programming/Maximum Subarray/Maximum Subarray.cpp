class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int pre = nums[0];  int ans = nums[0];
        
        for(int i = 1 ; i<nums.size() ; i++)
        {
            pre = max(pre+nums[i],nums[i]);
            ans = max(pre,ans);
            //cout << pre << " ";
        }
        
        return ans;
    }
};
