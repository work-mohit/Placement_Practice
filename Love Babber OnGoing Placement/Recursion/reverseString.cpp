#include<bits/stdc++.h>
using namespace std;

string reversed(string& str,int low, int high){
    if (high == 0)
        return str;
    if(low > high)
        return str;
    swap(str[low], str[high]);

    return reversed(str, low+1 , high-1);

}
int main(){
    string str;
    getline(cin,str);
    
    int len = str.length();
    reversed(str,0,len-1);
    cout<<str;
    return 0;
}