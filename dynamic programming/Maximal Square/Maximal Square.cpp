class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector < vector <int> > mp;
        mp.resize(matrix.size());
        for(int i = 0 ; i<matrix.size() ; i++) mp[i].resize(matrix[i].size());
        int ans = 0;
        for(int i = 0 ; i<matrix.size() ; i++)
        {
            mp[i][0] = (matrix[i][0] == '1')?(1):(0);
            if(mp[i][0]) ans = 1;
        }
        for(int i = 0 ; i<matrix[0].size() ; i++)
        {
            mp[0][i] = (matrix[0][i] == '1')?(1):(0);
            if(mp[0][i]) ans = 1;
        }
        for(int i = 1 ; i<matrix.size() ; i++)
        {
            for(int j = 1; j<matrix[i].size() ; j++)
            {
                if(mp[i-1][j-1]!=0 && mp[i-1][j]!=0 && mp[i][j-1]!=0 && matrix[i][j] == '1')
                {
                    int a = min(mp[i-1][j-1],mp[i-1][j]);
                    a = min(a,mp[i][j-1]);
                    mp[i][j] = a+1;
                    ans = max(ans,a+1);
                }
                else
                {
                    mp[i][j] = (matrix[i][j] == '1')?(1):(0);
                    if(mp[i][j]) ans = max(ans,1);
                }
            }
        }    
        return ans*ans;
    }
};
