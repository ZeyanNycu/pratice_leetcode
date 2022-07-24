class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int *ans = new int [26];
        int *temp = new int [p.length()];
        for(int j = 0 ; j<26 ; j++) ans[j] = 0;
        for(int i = 0 ; i<p.length() ; i++) temp[i] = 0;
        ans[p[0]-'a'] = 1;
        temp[0] = 1;
        for(int i = 1; i<p.length() ; i++)
        {
            if( (p[i]-'a'-1) == p[i-1]-'a' || (p[i]-'a'-1)+26 == p[i-1]-'a')
            {
                temp[i] = 1+temp[i-1];
                ans[p[i]-'a'] = max(ans[p[i]-'a'],1+temp[i-1]);
            }
            else
            {
                ans[p[i]-'a'] = max(ans[p[i]-'a'],1);
                temp[i] = 1;
            }
        }
        int total = 0;
        for(int i = 0 ; i<26 ; i++) total+=ans[i];
        return total;
    }
};
