Node* merger(Node* a,Node *b){
    
    Node* head = new Node(0);
    Node* last = head;
    
    while(a && b){
        
        if(a->data <= b->data){
            last->bottom = a;
            a = a->bottom;
        }else{
            last->bottom = b;
            b = b->bottom;
        }
        
        last = last->bottom;
    }
    
    last->bottom = a ? a : b;
    
    return head->bottom;
}
Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL)
        return root;
    
    root->next = flatten(root->next);
    root = merger(root, root->next);
    return root;
}