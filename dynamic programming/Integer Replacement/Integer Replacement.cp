class Solution {
public:
    int integerReplacement(int n) {
        int ans = find_ans(n);
        return ans; 
    }
    int find_ans(long long n)
    {
        if(n==1) return 0;
        if(n%2==0)  return find_ans(n/2)+1;
        else    return min( find_ans(n-1),find_ans(n+1) )+1;
    }
};
