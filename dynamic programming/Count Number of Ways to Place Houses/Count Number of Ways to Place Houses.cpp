class Solution {
public:
    int countHousePlacements(int n) {
        long long pre_1 = 2,pre_2 = 1;
        for(int i = 2; i<=n ; i++)
        {
            long long temp = pre_1;
            pre_1  += pre_2;  //前面代表有 後面代表沒有的組合
            pre_1 %= 1000000007;
            pre_2 = temp;
        }
        long long ans = 0;
        int times = pre_1/1000;
        int remain = pre_1%1000;
        for(int i = 0 ; i<times ; i+=1)
        {
            ans += pre_1*1000;
            ans %= 1000000007;
        }
        ans += pre_1*remain;
        ans %= 1000000007;
        return ans;
        
    }
};
