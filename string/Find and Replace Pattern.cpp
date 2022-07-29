class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> ans;
        for(int i = 0 ; i<words.size() ; i++)
        {
            map<char,char> t;
            if(jud(t,words[i],pattern)) ans.push_back(words[i]);
        }
        return ans;
    }
    bool jud(map<char,char> t,string w,string p)
    {
        if(p.length()!=w.length()) return false;
        bool v[26];
        for(int i = 0 ; i<26 ; i++) v[i] = false;
        for(int j = 0 ; j<w.length() ; j++)
        {
            if(t.count(w[j]) == 0)
            {
                if(v[p[j]-'a']) return false;
                t[w[j]] = p[j];
                v[p[j]-'a'] = true;
            }
            if(t[w[j]] != p[j]) return false;
        }
        return true;
    }
};
