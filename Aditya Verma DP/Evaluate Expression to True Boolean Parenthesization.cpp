class Solution{
public:
    int solve(string s, int i , int j, bool isTrue){
        // ye toh empty string hai

        if(i > j)
            return false;

        // jb i j ek hi hai tb check krlo ki kya chaiye us particular expression se hume
        // true chaiye toh check krlo charater me true hai ya nhi aur else false chahiye toh
        // check krlo character me false hai ya nhi
    
        if(i == j){
            if(isTrue == true)
                return s[i]=='T';
            else
                return s[i] == 'F';
        }
        // ye last me return krna hoga 
        int ans = 0;
        
        // hamare pass hamesha do operands and ek operator hoga 
        // ek left toh ek right 
        // left wala true bhi ho skta and false bhi and same for the right 
        // ab hum ye chaaro calculate kr lenge
        // left true , left false, right true , right false
        for(int k = i+1; k <= j-1; k += 2){
            int lT = solve(s, i , k-1, true);
            int lF = solve(s, i , k-1, false);
            int rT = solve(s, k+1 , j, true);
            int rF = solve(s, k+1 , j, false);
            

            // kisi bhi do oprands ka result operator pr depend krta toh diff operator ke liye
            // diff calculation krni padegi 
            // for eg and(&) ke case me agr true result chahiye toh dono operand jb true honge
            // tbhi result me add hona chahiye
            
            if(s[k] == '&'){
                if(isTrue == true){
                    ans += lT * rT;
                }else{
                    ans += lT * rF + lF * rT + lF * rF;
                }
            }
            else if(s[k] == '|'){
                if(isTrue == true){
                    ans += lT * rT + lT * rF + lF * rT;
                }else{
                    ans += lF * rF;
                }
            }
            else if(s[k] == '^'){
                if(isTrue == true){
                    ans +=  lT * rF + lF * rT;
                }else{
                    ans += lF * rF + lT * rT ;
                }
            }
            
        } // end of for 
        return ans;
    }
    int countWays(int N, string S){
        return solve(S, 0 , N-1, 1);
    }
};