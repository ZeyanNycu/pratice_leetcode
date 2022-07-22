class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int ans = 0;
        for(auto it:nums) ans += it;
        if(ans%2) return false;
        vector <bool> v(ans+1);
        for(int i = 1 ; i<=ans ; i++) v[i] = false;
        v[0] = true;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            for(int j = ans ; j>=nums[i] ; j--) v[j] = (v[j] || v[j-nums[i]]);
        }
        //for(auto it:v) cout << it << " ";
        //cout << endl;
        return v[ans/2];
    }
};
