// https://practice.geeksforgeeks.org/problems/string-formation-from-substring2734/1
class Solution{
public:		
	int isRepeat(string s)
	{
	    int n = s.size();
        for(int i = n/2 ; i>= 1; i--){
            // whole string length ko substring divide kre tbhi kuch hoga
            if(n % i == 0){
                int num_repeated = n / i;
                 
                string substr = s.substr(0,i);
                
                string temp = "";
                for(int i = 0 ; i < num_repeated; i++){
                    temp.append(substr);
                }
                if(temp == s){
                    return true;
                }
            }
        }
        return false;
	}
};