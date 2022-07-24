class Solution {
public:
    int total = 0;
    vector <int> m;
    vector <int> s;
    bool makesquare(vector<int>& matchsticks) {
        m.assign(matchsticks.begin(),matchsticks.end());
        for(auto it: matchsticks)   total += it;
        for(int i = 0 ; i<4 ; i++) s.push_back(0);
        if(total%4) return false;
        total /=4;
        sort(m.rbegin(), m.rend());
        return solve(0);
    }
    bool solve(int ind)
    {
        if(ind>=m.size())
        {
            return s[0] == s[1] && s[1] == s[2] && s[2] == s[3] ;
        }
        for(int i = 0 ; i<4 ; i++)
        {
            if(s[i]+m[ind]>total) continue;
            s[i] += m[ind];
            if(solve(ind+1)) return true;
            s[i] -= m[ind];
        }
        return false;
    }
};
