//// with bfs and dfs , just change the name of the function in the distanceK method.

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> visited;
    
    void findParent(TreeNode* root, TreeNode* target){
        if(!root || root==target)
            return;
        
        if(root->left){
            parent[root->left] = root;
            findParent(root->left , target);
        }
        if(root->right){
            parent[root->right] = root;
            findParent(root->right, target);
        }
    }
    void dfs(TreeNode* root, int k , vector<int> &res){
        if(root==NULL || visited[root])
            return;
        visited[root] = true;
        
        if(k == 0){
            res.push_back(root->val);
            return;
        }
        if(root->left)
            dfs(root->left, k-1 , res);
        if(root->right)
            dfs(root->right, k-1 , res);
        TreeNode* p = parent[root];
        if(p)
            dfs(p, k-1, res);
        
    }
    void bfs(TreeNode* root, int k, vector<int> &res){
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            if(cnt++ == k)
                break;
            for(int i = 0; i < n; i++){
                TreeNode* fnode = q.front();
                q.pop();
                visited[fnode] = true;
                if(fnode->left && !visited[fnode->left])
                    q.push(fnode->left);
                
                if(fnode->right && !visited[fnode->right])
                    q.push(fnode->right);
                
                if(parent[fnode] && !visited[parent[fnode]])
                    q.push(parent[fnode]);
            }  
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        
        findParent(root, target);
        bfs(target, k,res);
        
        return res;
    }
};