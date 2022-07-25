class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int bag[strs.size()+1][m+1][n+1];
        vector < pair<int,int> > len;
        for(int i = 0 ; i<strs.size() ; i++)
        {
            int n_0 = count(strs[i].begin(),strs[i].end(),'0');
            int n_1 = count(strs[i].begin(),strs[i].end(),'1');
            len.push_back(make_pair(n_0,n_1));
        }
        for(int j = 0 ; j<=m ; j++)
        {
            for(int k = 0 ; k<=n ; k++)
            {
                for(int i = 0; i<=strs.size() ; i++)
                {
                    if(i==0)
                    {
                        bag[i][j][k] = 0;
                        continue;
                    }
                    bag[i][j][k] = bag[i-1][j][k];
                    if(j>=len[i-1].first && k>=len[i-1].second)
                        bag[i][j][k] = max(bag[i][j][k],bag[i-1][j-len[i-1].first][k-len[i-1].second]+1);
                }
            }
        }
        /*for(int i = 0 ; i<=m ; i++)
        {
            for(int j = 0 ; j<=n ; j++) cout << bag[3][i][j] << " ";
            cout << endl;
        }*/
        return bag[strs.size()][m][n];
    }
};
