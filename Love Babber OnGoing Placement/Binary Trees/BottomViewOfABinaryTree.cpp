class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
        //  HD , node-> data
        map<int , int> m;
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> frontNode = q.front();
            q.pop();
            
            int hd = frontNode.second;
            Node* node = frontNode.first;
            // if(m.find(hd) == m.end())    // abki baar condition mt dekho sirf daal do last me jo bachega wo hi dikhega
            m[hd] = node->data;
            
            if(node->left)
                q.push(make_pair(node->left, hd-1));
            if(node->right)
                q.push(make_pair(node->right, hd+1));
            
        }
        for(auto x: m){
            ans.push_back(x.second);
        }
        return ans;
    }

};