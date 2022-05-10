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


////////////////////////////////
// recursion + memoization using hashmap
class Solution{
public:
    unordered_map<string, int> mp;
    int solve(string s, int i , int j, bool isTrue){
        if(i > j)
            return false;
        if(i == j){
            if(isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if(mp.find(temp) != mp.end())
            return mp[temp];
            
        int ans = 0;
        
        for(int k = i+1; k <= j-1; k += 2){
            int lT = solve(s, i , k-1, true);
            int lF = solve(s, i , k-1, false);
            int rT = solve(s, k+1 , j, true);
            int rF = solve(s, k+1 , j, false);
            
            
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
        return mp[temp] = ans % 1003;
    }
    int countWays(int N, string S){
        return solve(S, 0 , N-1, 1);
    }
};

////////////////////////////
//// memoization using vector

int func(string &nums,int i,int j,int istrue,vector<vector<vector<int>>> &dp){
       if(i>j) return 0;
       if(i==j){
           if(istrue) return nums[i]=='T';
           else return nums[i]=='F';
       }
       if(dp[i][j][istrue]!=-1) return dp[i][j][istrue]; 
       int ways=0;
       for(int k=i+1;k<=j-1;k+=2){
           int lt=func(nums,i,k-1,1,dp);
           int lf=func(nums,i,k-1,0,dp);
           int rt=func(nums,k+1,j,1,dp);
           int rf=func(nums,k+1,j,0,dp);
           if(nums[k]=='&'){
               if(istrue) ways+=(lt*rt);
               else ways+=((rt*lf)+(rf*lt)+(lf*rf));
           }
           else if(nums[k]=='|'){
               if(istrue) ways+=((rt*lf)+(rf*lt)+(lt*rt));
               else ways+=(lf*rf);
           }
           else{
               if(istrue) ways+=((lt*rf)+(lf*rt));
               else ways+=((lf*rf)+(lt*rt));
           }
       }
       return dp[i][j][istrue]=(ways%1003);
   }
   int countWays(int N, string S){
       // code here
       vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
       return func(S,0,N-1,1,dp);
   }