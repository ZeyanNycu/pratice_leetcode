class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector <string> ans,cmp(words1);
        vector <int> dp(26,0);
        for(int i = 0 ; i<words2.size() ; i++)
        {
            vector <int> temp(26,0);
            for(int j = 0 ; j<words2[i].size() ; j++)   temp[words2[i][j]-'a']++;
            for(int j = 0 ; j<26 ; j++) dp[j] = max(dp[j],temp[j]);
        }
        //for(auto it:dp) cout << it << endl;
        for(int i = 0 ; i<words1.size() ; i++)
        {
            bool sign = true;
            vector <int> temp(26,0);
            for(int j = 0; j<words1[i].size() ; j++)   temp[words1[i][j]-'a']++;
            for(int j = 0 ; j<26 ; j++)
            {
                if(temp[j]>=dp[j]) continue;
                sign = false;
                break;
            }
            if(sign) ans.push_back(words1[i]);
        }
        return ans;
    }
};
