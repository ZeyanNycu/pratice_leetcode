class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
            if(m.count(used)) return m[used];
            for(int i = 1; i<=length ; i++)
            {
                int cmp = (1 << i);
                if( (used & cmp) == 0)
                {
                    if(i>=total || !canWin(length,total-i, used | cmp, m))
                    {
                        m[used] = true;
                        return true;
                    }
                }
            }
            m[used] = false;
            return false;
    }
};
