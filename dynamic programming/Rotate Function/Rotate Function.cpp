class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int a_b_c =0,ans = 0,pre;
        int a = nums[0];
        for(auto it: nums) a_b_c +=it;  a_b_c -= a;
        for(int i = 0 ; i<nums.size() ; i++) ans += (i*nums[i]);
        pre = ans;
        for(int i = 1; i<nums.size() ; i++)
        {
            int temp = (nums.size()-1)*a-(a_b_c)+pre;
            ans = max(ans,temp);
            if(i == nums.size()-1) continue;
            a_b_c -= (nums[i]-a);
            a = nums[i];
            pre = temp;
        }
        return ans;
    }
};
