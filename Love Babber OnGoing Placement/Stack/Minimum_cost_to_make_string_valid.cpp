// general expression is   (a + 1)/2 + (b+1)/2
// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
#include<stack>
int findMinimumCost(string str) {
  // Write your code here
    // 1 Remove invalid expressions
    stack<char> s;
    if(str.length() & 1)  // invalid string 
        return -1;
    // 2 remove valied expressions and then we left of 3 types 
    //  1.  {{{{{{{{{{
    //  2.  }}}}}}}}}}
    //  3.  }}}}}}{{{{{{
  	
    
    for(int i = 0; i< str.length(); i++){
        if(str[i] == '{')
            s.push('{');
        else{
            if(s.size() != 0 && s.top() == '{' )
                s.pop();
            else
                s.push('}');
        }        
    }
    if(s.empty())
        return 0;
    int leftcnt = 0;
    int rightcnt = 0;
    while(!s.empty()){
       	if(s.top() == '{')
            leftcnt++;
        else
            rightcnt++;
        s.pop();
    }
    return (leftcnt + 1)/2 + (rightcnt + 1)/2;
}