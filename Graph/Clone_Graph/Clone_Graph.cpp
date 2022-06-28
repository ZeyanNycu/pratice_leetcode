class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* ans;
        if(node == NULL) return NULL;
        Node* pos = new Node;
        bool sign = true;
        map <int,Node*> v,v_copy;
        vector <Node*> bfs,bfs_copy;
        bfs.push_back(node);
        v[node->val] = node;
        v_copy[node->val] = pos;
        while(bfs.size())
        {
            Node* top = bfs[0];
            bfs.erase(bfs.begin());
            pos->val = top->val;
            for(auto i:top->neighbors)
            {
                if( v.count(i->val) )
                {
                    pos->neighbors.push_back(v_copy[i->val]);
                    continue;
                }
                Node* newnode = new Node(i->val);
                pos->neighbors.push_back(newnode);
                v[i->val] = i;
                v_copy[i->val] = newnode;
                bfs.push_back(i);
                bfs_copy.push_back(newnode);
            }
            if(sign)
            {
                ans = pos;
                sign = false;
            }
            if(bfs_copy.size())
            {
                pos = bfs_copy[0];
                bfs_copy.erase(bfs_copy.begin());
            }
        }
        return ans;
    }
};
