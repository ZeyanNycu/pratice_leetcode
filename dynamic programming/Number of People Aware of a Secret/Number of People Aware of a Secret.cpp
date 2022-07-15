class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector <int> p;
        p.resize(n+1);
        p[1] = 1;
        for(int i = 2; i<=n ; i++)
        {
            p[i] = 0;
            int pre = max(i-forget+1,1);
            for(int j = pre; j<=i-delay ; j++)
            {
                p[i] += p[j];
                p[i] %= 1000000007;
            }
        }
        int start = n-forget+1;
        int ans = p[start];
        start++;
        //for(auto it: p) cout << it << endl;
        for(int i = start ; i<=n ; i++)
        {
            ans+=p[i];
            ans %= 1000000007;
        }
        return ans;
    }
};
