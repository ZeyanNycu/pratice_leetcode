class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector <int> index(primes.size(),0);
        vector <long long> ans;
       // for(auto it:index) cout << it << endl;
        ans.push_back(1);
        for(int i = 1 ; i<n ; i++)
        {
            long long  min=ans[index[0]]*primes[0];
            vector <long long> ind(1,0);
            for(int j = 1 ; j<index.size() ; j++)
            {
                long long temp = ans[index[j]]*primes[j];
                //cout << temp << "++++++++++++" << " ";
                if(min>temp)
                {
                    min = temp;
                    ind.clear();
                    ind.push_back(j);
                }
                else if(min == temp) ind.push_back(j);
            }
            for(auto it:ind) index[it]++;
            ans.push_back(min);
        }
        return ans[n-1];
    }
};
