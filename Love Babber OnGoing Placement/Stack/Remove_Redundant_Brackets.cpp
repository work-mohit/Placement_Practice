#include<stack>
bool findRedundantBrackets(string& str)
{	
    stack<char> s;
    for(int i = 0 ; i < str.length(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            s.push(ch);
        }    
        else{
            if(ch ==')'){
                bool flag = true;
                while(s.top() != '('){
                    char top = s.top();
                    if(top == '+' || top == '-' || top == '/' || top == '*'){
                        flag = false;
                    }
                    s.pop();
                }
                if(flag == true)
                    return true;
                s.pop();
            }     
        }
    }
   return false;
}