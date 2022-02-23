class Solution
{
    public:
    
    bool isIdentical(Node *r1, Node *r2)
    {   
        if(r1 == NULL && r2 == NULL) // if both null means both reaches to there end
            return true;
        if(r1 == NULL || r2 == NULL)  // from r1 and r2 only one is NUll so here we return false
            return false;
        
            
        if(r1->data != r2->data){
            return false;
        }else{
            return isIdentical(r1->left, r2->left)&& isIdentical(r1->right, r2->right);
        }
        
    }
};