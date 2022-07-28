class Solution {
public:
    static bool cmp(char a,char b)
    {
        return a<b;
    }
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end(),cmp);
        sort(t.begin(),t.end(),cmp);
        if(s == t) return true;
        return false;
    }
};
