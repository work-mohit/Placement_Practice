#include<bits/stdc++.h>
using namespace std;
void reverse(string& str){
    stack<char> s;
    for(int i = 0; i < str.size(); i++){
        s.push(str[i]);
    }
    int i = 0;
    while(!s.empty()){
        str[i] = s.top();
        s.pop();
        i++;
    }
    return ;
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "this will be reversed by stack";
    reverse(str);
    cout<<str;
    return 0;
}