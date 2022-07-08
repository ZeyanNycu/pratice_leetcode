class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        vector < vector <bool> > g(s1.size()+1, vector <bool> (s2.size()+1));
        g[0][0] = true;
        for(int i = 1 ; i<=s1.size() ; i++) g[i][0] = (g[i-1][0] && s1[i-1] == s3[i-1]);
        
        for(int i = 1 ; i<=s2.size() ; i++) g[0][i] = (g[0][i-1] && s2[i-1] == s3[i-1]);
        for(int i = 1 ; i<=s1.size() ; i++)
        {
            for(int j = 1; j<=s2.size() ; j++)
            {
                g[i][j] = (g[i-1][j] && s1[i-1] == s3[i-1+j]) || (g[i][j-1] && s2[j-1] == s3[i-1+j]);
            }
        }
        return g[s1.length()][s2.length()];
    }
};
