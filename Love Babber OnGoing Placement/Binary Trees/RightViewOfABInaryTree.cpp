// using deque 

#include<deque>
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> v;
    	deque<Node*> dq;
    	
    	dq.push_back(root);
    	v.push_back(root->data);
        Node* temp = NULL;
        bool level = 1;
        
        while(!dq.empty()){
            int n = dq.size();
            
            for(int i =0 ; i < n;i++){
                
                // popping (Nikalna kha se hai)
                if(level % 2 == 0){      // if even hai toh piche se nikalo aur piche se daalo 
                    temp = dq.back();
                    dq.pop_back();
                }else{                  // age nhi hai toh aage se daalo aage se nikalo
                    temp = dq.front();
                    dq.pop_front();
                }
                
                // pushing (Dalna kha se hai)
                if(level % 2 != 0){      // eg abhi 1st level pe hai next ka phle right dalo then left 
                    if(temp->right){
                        dq.push_back(temp->right);
                        v.push_back(temp->right->data);
                    }        
                    if(temp->left){
                        dq.push_back(temp->left);
                        v.push_back(temp->left->data);
                    }
                }
                else if(level % 2 == 0){   // agr 2nd level pr hai toh next level me hume left se chahiye hoga toh left phle push kro 
                    if(temp -> left){                   // phle left daalo 
                        dq.push_front(temp->left);
                        v.push_back(temp->left->data);
                    }
                    if(temp->right){
                       dq.push_front(temp->right);       // phir right daalo
                       v.push_back(temp->right->data);
                    }
                   
                }
            }
            level++;    // yha pr ek level khatam ho chuki hai
        }
        return v;	
    }
};

// using queue 


