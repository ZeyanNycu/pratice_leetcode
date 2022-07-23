class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector < pair<int,int> > a;
        for(int i = 0 ; i<intervals.size() ; i++) a.push_back(make_pair(intervals[i][0],intervals[i][1]));
        sort(a.begin(),a.end(),cmp);
        int cnt = 0,end = -9999999;
        for(int i = 0 ; i<a.size() ; i++)
        {
            if(end<=a[i].first)    end = a[i].second;
            else cnt++;
        }
        return cnt;
    }
};
