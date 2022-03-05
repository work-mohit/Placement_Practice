class Solution {
  public:
    void makeMappingAndFindTarget(Node* root, int target, map<Node*,Node*> &nodeToParent, Node* &startFrom){
        if(root == NULL)
            return;
        if(root->data == target)   
            startFrom = root;
        
        if(root->left)
            nodeToParent[root->left] = root;
        if(root->right)
            nodeToParent[root->right] = root;
        
        makeMappingAndFindTarget(root->left, target, nodeToParent, startFrom);
        makeMappingAndFindTarget(root->right, target, nodeToParent, startFrom);
    }
    int findBurningTime(Node* startFrom, map<Node*,Node*> nodeToParent){
        queue<Node*> q;    
        map<Node* , bool> visited; 
        int cnt = 0;
        q.push(startFrom);
        visited[startFrom] = true;
        
        while(!q.empty()){
            int n = q.size();
            bool haveAdded = false;
            for(int i = 0; i < n; i++){
                Node* frontNode = q.front();
                q.pop();
                if(frontNode->left && !visited[frontNode->left]){
                    visited[frontNode->left] = true;
                    q.push(frontNode->left);
                    haveAdded = true;
                }
                if(frontNode->right && !visited[frontNode->right]){
                    visited[frontNode->right] = true;
                    q.push(frontNode->right);
                    haveAdded = true;
                }
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    visited[nodeToParent[frontNode]] = true;
                    q.push(nodeToParent[frontNode]);
                    haveAdded = true;
                }
            }
            
            if(haveAdded)
                cnt++;
            
        }
        
        
        return cnt;
        
    }
    int minTime(Node* root, int target) 
    {
        if(root == NULL)
            return 0;
        map<Node*,Node*> nodeToParent;
        nodeToParent[root] = NULL;
        Node* startFrom;
        
        // step 1 and step 2 : complete : make mappping to parent node and 
        // find the target from where we have to start burning of the tree
        
        makeMappingAndFindTarget(root, target, nodeToParent, startFrom);
        
        // find burn time
        
        return findBurningTime(startFrom, nodeToParent);
        
    }
};