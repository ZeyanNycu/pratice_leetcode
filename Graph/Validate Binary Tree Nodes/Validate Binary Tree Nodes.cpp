class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       vector < vector <int> > g;
        set <int> find_root;
        g.resize(n);
        for(int i = 0; i<n ; i++)
        {
            if(leftChild[i] != -1)
            {
                g[i].push_back(leftChild[i]);
                find_root.insert(leftChild[i]);
            }
            if(rightChild[i] != -1)
            {
                g[i].push_back(rightChild[i]);
                find_root.insert(rightChild[i]);
            }
        }
        int root = -1;
        for(int i=0; i<n ; i++)
        {
            if(find_root.count(i) == 0) 
            {
                root = i;
                break;
            }
        }
        if(root == -1) return false;
        queue <int> bfs;
        bool* v = new bool [n];
        for(int i = 0 ; i<n ; i++) v[i] = false;
        v[root] = true;
        bfs.push(root);
        while(bfs.size())
        {
            int top = bfs.front();
            bfs.pop();
            for(int i = 0; i<g[top].size() ; i++)
            {
                if(v[g[top][i]]) return false;
                bfs.push(g[top][i]);
                v[g[top][i]] = true;
            }
        }
        for(int i = 1; i<n ; i++) if(!v[i]) return false;
        return true;
    }
};
