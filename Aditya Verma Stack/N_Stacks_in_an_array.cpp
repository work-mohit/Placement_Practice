// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0

class NStack
{
public:
    // Initialize your data structure.
    int s , n, freespot;
    int *arr, *top,*next;
    NStack(int N, int S)
    {	
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];
        // top initialization
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }
        // next initialization
        for(int i = 0; i < s; i++){
            next[i] = i+ 1;
        }
        next[s-1]= -1;   // last element don't have any next element 
        
        freespot = 0;
        
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // cheack for overflow
        if(freespot == -1)
            return false;
        
       // find index   jo ki hoga freespot
       int index = freespot;
       // update freespot 
       freespot = next[index];
       // update value at index
       arr[index] = x;
       //  update next
        next[index] = top[m-1];
        // update top
        top[m-1]  = index;
        
        return true;
        
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
		// check underflow
        if(top[m-1] == -1)
            return -1;
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};