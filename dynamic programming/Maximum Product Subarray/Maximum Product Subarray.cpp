class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        set <int> r;
        r.insert(nums[0]);
        for(int i = 1; i<nums.size() ; i++)
        {
            set <int> temp;
            for(auto it: r)
            {
                int a = it*nums[i];
                ans = max(a,ans);
                temp.insert(a);
            }
            r.clear();
            r.insert(temp.begin(),temp.end());
            r.insert(nums[i]);
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};
