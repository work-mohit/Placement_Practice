class TwoStack {

public:

    int *arr, top1 , top2, size;
    TwoStack(int s) {
        this->size = s;
        arr = new int[size];
        top1= -1;
        top2 = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
    	if(top2 - top1 > 1){
            top1 = top1+1;
            arr[top1] = num;
        } 
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1){
            top2= top2-1;
            arr[top2]  = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 != -1){
            int ele = arr[top1];
            top1 = top1 -1;
            return ele;
        }else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if(top2 < size){
            int ele = arr[top2];
            top2 = top2 + 1;
            return ele;
        }   
        else{
            return -1;
        }    
    }
};
