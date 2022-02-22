/*
Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.

*/

class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> stk;
        int maxcnt =0 , cnt = 0;
        stk.push(-1);
        for(int i =0; i< s.length(); i++){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.size() == 0)
                    stk.push(i);
                else
                    maxcnt = max(maxcnt , i - stk.top());
            }
        }
        return maxcnt;
    }
};