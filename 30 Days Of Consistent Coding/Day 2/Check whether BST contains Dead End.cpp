//https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

/* 
    The problem is we have given a bst and it have nodes containing >0 integers
    A dead end is the node after which we can't insert a node in the bst 

              8
            /   \           In this example 1 is the dead end.
           5      9         we can't insert to left (since it will become to zero)
         /  \               and in left we already have max range 2.
        2    7 
       /
      1                 


    Base condition : Agr null hai toh nhi hoga 

    *agr hum right limit se 1 kam ya left limit se ek jyada hai tb dead end hai 
        tb return true kr denge 
    baaki recursive calling kr denge left aur right subtree ke liye
*/


bool helper(Node* root, int l , int r){
    if(root == NULL)
        return false;
    if(root->data == r-1 && root->data == l+1){    // main section 
       return true;
    }
        
    return (helper(root->left , l, root->data) || helper(root->right , root->data, r));
}
bool isDeadEnd(Node *root)
{
    return helper(root, 0, INT_MAX);
}