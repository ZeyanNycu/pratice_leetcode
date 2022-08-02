class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector <int> left_top;
        vector < vector <bool> > grid(n,vector <bool> (n,true));
        vector < vector< pair<int,int> > > dp_1(n,vector < pair<int,int> > (n,make_pair(-1,-1)));//left top
        vector < vector< pair<int,int> > > dp_2(n,vector < pair<int,int> > (n,make_pair(-1,-1)));//right down
        for(int i = 0 ; i<mines.size() ; i++)   grid[mines[i][0]][mines[i][1]] = false;
        for(int i = 0 ; i<n-1 ; i++)
        {
            for(int j = 0 ; j<n-1 ; j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0 && j==0) continue;
                    if(grid[i][j] && i==0) dp_1[i][j] = make_pair(-1,0);
                    if(grid[i][j] && j==0) dp_1[i][j] = make_pair(0,-1); 
                    continue;
                }
                if(grid[i][j]) dp_1[i][j] = make_pair(dp_1[i][j-1].first+1,dp_1[i-1][j].second+1);
            }
        }
        for(int i = n-1 ; i>0 ; i--)
        {
            for(int j = n-1 ; j>0 ; j--)
            {
                if(i==n-1 || j==n-1)
                {
                    if(i==n-1 && j==n-1) continue;
                    if(grid[i][j] && i==n-1) dp_2[i][j] = make_pair(-1,0);
                    if(grid[i][j] && j==n-1) dp_2[i][j] = make_pair(0,-1);
                    continue;
                }
                if(grid[i][j]) dp_2[i][j] = make_pair(dp_2[i][j+1].first+1,dp_2[i+1][j].second+1);
            }
        }
        int ans = (mines.size() != n*n);
        bool sign = false;
        for(int i = 1 ; i<n-1 ; i++)
        {
            for(int  j = 1 ; j<n-1 ; j++)
            {
                if(grid[i][j])
                {
                    int left_min = min(dp_1[i][j].first,dp_1[i][j].second);
                    int right_min = min(dp_2[i][j].first,dp_2[i][j].second);
                    int temp = min(left_min,right_min);
                    //cout << i << " " << j << " " << temp << endl;
                    if(temp) sign = true;
                    ans = max(ans,temp);
                }
            }
        }   
        if(sign)    return ans+1;
        return ans;
    }
};
