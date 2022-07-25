class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans(2,-1);
        if(nums.size() == 0) return ans;
        ans[0] = find_start(nums.size(),nums,target);
        int f = max(0,ans[0]);
        ans[1] = find_end(f,nums,target);
        return ans;
    }
    int find_start(int m,vector <int> nums,int t)
    {
        int f = 0,end = m;
        while(f<end)
        {
            int mid = (f+end)/2;
            if(nums[mid]<t) f = mid+1;
            else end = mid;
        }
        if(end == nums.size()) return -1;
        if(nums[end] != t) return -1;
        return end;
    }
     int find_end(int m,vector <int> nums,int t)
    {
        int f = m;
        int end = nums.size()-1;
        while(f<end)
        {
            int mid = (f+end);
            mid = (mid+( (f+end)%2 ) )/2;
            if(nums[mid]<=t) f = mid;
            else end = mid-1;
        }
        if(nums[f] != t) return -1;
        return f;
    }
};
