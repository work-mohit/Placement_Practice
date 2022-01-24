#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str,int low, int high){
   
    if(low >= high)
        return true;

    if(str[low] == str[high])
        return checkPalindrome(str, low + 1 , high-1);
    else{
        return false;
    }
    

}
int main(){
    string str;
    getline(cin,str);
    
    int len = str.length();

    if(checkPalindrome(str,0,len-1))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;
    
    return 0;
}