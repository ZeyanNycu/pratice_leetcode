class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        else if (n==2) return max(nums[0],nums[1]);
        vector <int> ans_1;
        ans_1.resize(n);
        ans_1[0] = nums[0];
        ans_1[1] = max(nums[0],nums[1]);
        for(int i = 2; i<n-1 ;i++)
        {
            ans_1[i] = max(ans_1[i-1],ans_1[i-2]+nums[i]);
        }
        
        vector <int> ans_2;
        ans_2.resize(n);
        ans_2[1] = nums[1];
        ans_2[2] = max(nums[1],nums[2]);
        for(int i = 3; i<n ; i++)
        {
            ans_2[i] = max(ans_2[i-1],ans_2[i-2]+nums[i]);
        }
        return max(ans_2[n-1],ans_1[n-2]);
    }
};
