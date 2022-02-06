#include<bits/stdc++.h>
#define row 3
#define col 3
using namespace std;
void Recursion(string sentence[row][col], int temp_1, int temp_2, string arr[row]){
   arr[temp_1] = sentence[temp_1][temp_2];
   if(temp_1 == row - 1){
      for(int i=0; i < row; i++){
         cout << arr[i] << " ";
      }
      cout << endl;
      return;
   }
   for(int i=0; i < col; i++){
      if(sentence[temp_1+1][i] != ""){
         Recursion(sentence, temp_1+1, i, arr);
      }
   }
}
void Recursive_Print(string sentence[row][col]){
   string arr[row];
   for(int i=0; i < col; i++){
      if(sentence[0][i] != ""){
         Recursion(sentence, 0, i, arr);
      }
   }
}
int main(){
   string sentence[row][col] = {{"Ajay", "sanjay"},{"Like", "is"},{"Reading", "eating"}};
   Recursive_Print(sentence);
   return 0;
}