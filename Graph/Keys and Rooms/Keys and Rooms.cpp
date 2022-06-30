class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool* v = new bool [rooms.size()];
        for(int i = 0 ; i<rooms.size() ; i++) v[i] = false;
        queue <int> bfs;
        bfs.push(0);
        v[0] = true;
        while(bfs.size())
        {
            int top = bfs.front();
            bfs.pop();
            for(int i = 0; i<rooms[top].size() ; i++)
            {
                if(v[rooms[top][i]]) continue;
                v[rooms[top][i]] = true;
                bfs.push(rooms[top][i]);
            }
        }
        for(int i = 0 ; i<rooms.size() ; i++)   if(!v[i]) return false;
        return true;
    }
};
