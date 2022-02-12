bool isValidParenthesis(string str)
{
    stack<int> s;
   	int i = 0;
    while(i < str.size()){
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else if(str[i] == ')'){
            if(s.size() == 0)
                return false;
            if(s.top() == '(')
                s.pop();
            else
                return false;
        }
        else if(str[i] == '}'){
            if(s.size() == 0)
                return false;
            if(s.top() == '{')
                s.pop();
            else
                return false;
        } else if(str[i] == ']'){
            if(s.size() == 0)
                return false;
            if(s.top() == '[')
                s.pop();
            else
                return false;
        }
        
        i++;
    }
    if(s.empty())
        return true;
    return false;
}