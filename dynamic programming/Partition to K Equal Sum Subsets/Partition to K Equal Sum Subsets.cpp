class Solution {
public:
    vector <int> n,con;
    int lim ;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n.assign(nums.begin(),nums.end());
        sort(n.rbegin(),n.rend());
        int total = 0;
        for(auto it: nums) total += it;
        if(total % k) return false;
        lim = total/k;
        con.resize(k);
        for(int i = 0 ; i<k ; i++) con[i] = 0;
        if(n[0]<=lim)   con[0] = n[0];
        else return false;
        if(con[0]+n[1]<=lim)
        {
            con[0] += n[1];
            if(jud(2)) return true;
            con[0] -= n[1];
        }
        con[1] = n[1];
        return jud(2);
    }
    bool jud(int ind)
    {
        if(ind == n.size())
        {
            int com = con[0];
            for(auto it:con)
            {
                if(com != it) return false;
            }
            return true;
        }
        for(int i = 0;i<con.size();i++)
        {
            if(con[i]+n[ind]>lim) continue;
            con[i] += n[ind];
            if(jud(ind+1)) return true;
            con[i] -= n[ind];
        }
        return false;
    }
};
