class Solution {
public:
    int numDecodings(string s) {
        vector <int> dis;
        if(s[0] == '0') return 0;
        dis.resize(s.length());
        dis[0] = 1;
        if(s.length()>1)
        {
            string temp = s.substr(0,2);
            if(s[1] != '0')
            {
                if(atoi(temp.c_str())<=26) dis[1] = 2;
                else dis[1] = 1;
            }
            else 
            {
                if(atoi(temp.c_str())<=26) dis[1] = 1;
                else dis[1] = 0;
            }
            for(int i = 2 ; i<s.length() ; i++)
            {
                if(s[i] != '0') dis[i] += dis[i-1];
                if(s[i-1] != '0')
                {
                    string temp = s.substr(i-1,2);
                    if(atoi(temp.c_str())<=26) dis[i]+= dis[i-2];
                }
            }
        }
        return dis[s.length()-1];
    }
};
