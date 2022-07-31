class Solution {
public:
    bool checkValidString(string s) {
        if(s.length() == 0) return true;
        vector < vector <bool> > dp(s.length(), vector <bool> (s.length(),false));
        for(int i = 0 ; i<s.length() ; i++)
        {
            if(s[i] == '*') dp[i][i] = true;
            if(i<s.length()-1)
            {
                if(s[i] == '(' || s[i] == '*')
                {
                    if(s[i+1] == ')' || s[i+1] =='*') dp[i][i+1] = true;
                }
            }
        }
        for(int i = 2 ; i<s.length() ; i++)
        {
            for(int j = 0; j<s.length()-i ; j++)
            {
                if(s[j] == '*' && dp[j+1][j+i]) dp[j][j+i] = true;
                else if(s[j] == '(' || s[j] == '*')
                {
                    for(int k = j+1 ; k<j+i+1 ; k++)
                    {
                        if( (s[k] == ')' || s[k] == '*') && 
                            (k == j+1 || dp[j+1][k-1]) &&
                          (k == j+i || dp[k+1][j+i]) ) dp[j][j+i] = true;
                    }
                }
            }
        }
        return dp[0][s.length()-1];
    }
};
