pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
   // find key 
    
    int pred = -1;
    int succ = -1;
    BinaryTreeNode<int>* temp = root;
    
    while(temp->data != key){
        if(temp->data > key){
            succ = temp -> data;
            temp = temp -> left;
        }else{
            pred = temp -> data;
            temp = temp -> right;
        }
    }
    // till now we have found our key and possible succ and pred
   // now the predecessor will be the max of the left sub tree
    // and the successor will be the the min element of the right sub tree
    
    // pred
    BinaryTreeNode<int>* leftTreeNode = temp -> left;
    while(leftTreeNode != NULL){
        pred = leftTreeNode ->data;
        leftTreeNode = leftTreeNode -> right;
    }
    
    // succ 
    BinaryTreeNode<int>* rightTreeNode = temp -> right;
    while(rightTreeNode != NULL){
        succ = rightTreeNode->data;
        rightTreeNode = rightTreeNode -> left;
    }
   return {pred ,succ};
     
}