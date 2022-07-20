class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <bool> dp;
        if(amount == 0) return 0;
        dp.resize(amount+1);
        for(int i = 1 ; i<=amount ; i++) dp[i] = false;
        dp[0] = true;
        queue < pair<int,int> > bfs;
        bfs.push(make_pair(0,0));
        while(bfs.size())
        {
            int top = bfs.front().first,step = bfs.front().second;
            bfs.pop();
            for(int i = 0 ; i<coins.size() ; i++)
            {
                if(top+coins[i]>amount || dp[top+coins[i]]) continue;
                dp[top+coins[i]]  = true;
                if(top+coins[i] == amount) return step+1;
                bfs.push(make_pair(top+coins[i],step+1));
            }
        }
        return -1;
    }
};
