class NumArray {
public:
    int store[30001];
    int len;
    int *n;
    NumArray(vector<int>& nums) {
        for(int i = 0 ; i<nums.size() ; i++) store[i] = nums[i];
        double a = sqrt(nums.size());
        len = ceil(nums.size()/(a));
        n = new int[len];
        for(int i = 0 ;i<len ; i++) n[i] = 0;
        for(int i = 0 ; i<nums.size() ; i++)
            n[i/len] += nums[i];
    }
    
    void update(int index, int val) {
        int ind = index/len;
        n[ind] = n[ind] - store[index] +val;
        store[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        int startblock = left/len;
        int endblock = right/len;
        if(startblock == endblock)
        {
            for(int i = left; i<=right ; i++) ans +=store[i];
        }
        else
        {
            for(int i = left; i<=(startblock+1)*len-1;i++) ans+=store[i];
            
            for(int i = startblock+1 ; i<=endblock-1 ; i++) ans+=n[i];
            
            for(int i = (endblock)*len ; i<=right ; i++) ans += store[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
