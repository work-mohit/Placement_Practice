void interLeaveQueue(queue < int > & q) {
    if(q.size()==1)
        return;
    // q = 1 2 3 4
    stack<int> s;
   	int n = q.size()/2;

    while(n > 0){
        s.push(q.front());
        q.pop();                // aage ke n/2 ko stack me daal do 
        n--;
    }  //q = 3 4  s= 1 2 

    while(!s.empty()){
        q.push(s.top());        // stack se nikal ke queue me piche add kr do or ab ye reverse ho chuke hai
        s.pop();
    }                               //  q = 3 4 2 1

   	n = q.size()/2;
    while(n > 0){           // aage ke size/2 element ko piche daal do 
        q.push(q.front());
        q.pop();
        n--;
    }                               // q = 2 1 3 4

   	n = q.size()/2;
    while(n > 0){
        s.push(q.front());            // fir se age walo ko stack me daal do taaki purana order mil jaaye unka
        q.pop();
        n--;
    }                       //q = 4 3 = 2 1 now this is what we need
    while(!s.empty()){
        q.push(s.top());
        s.pop();                // ab ek element stack se lo aur ek queue se.
        q.push(q.front());
        q.pop();
    }
   
}