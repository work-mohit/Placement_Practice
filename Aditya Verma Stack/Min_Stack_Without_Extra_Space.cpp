#include<bits/stdc++.h>
using namespace std;

// class MinStack{
//     public:
//         stack<int> s;
//         int min_ele;
//         MinStack(){
            
//         }
//         void push(int val){
//             if(s.size() == 0){
//                 s.push(val);
//                 min_ele = val;
//             }else{
//                 if(val >= min_ele){
//                     s.push(val);
//                 }else{
//                     s.push(2*val - min_ele);
//                     min_ele = val;
//                 }
//             }

//         }
//         int pop(){
//             if(s.size() == 0){
//                  return -1;
//             }
//             else {
//                 if(s.top() >= min_ele){
//                     s.pop();    
//                 }else{
//                     min_ele = 2 * min_ele - s.top();
//                     s.pop();
//                 }
//             }
//         }

//         int top(){
//             if(s.size() == 0)
//                 return -1;
//             else{
//                 if(s.top()<= min_ele)
//                     return min_ele;
//                 else 
//                     return s.top();
//             }
//         }
//         int getMin(){
//             if(s.size()== 0)
//                 return -1;
//             else
//                 return min_ele;
//         }
// };
class MinStack{
    public:
        stack<pair<int, int>> s;
        
        MinStack(){
            
        }
        void push(int val){
            if(s.size()==0){
                s.push({val,val});

            }else{
                if(val < s.top().second){
                    s.push({val, val});  
                }else{
                    s.push({val, s.top().second});
                }
            }
        }
        int pop(){
            if(s.size() == 0)
                return -1;
            s.pop();
        }

        int top(){
            if(s.size()== 0)
                return  -1;
            return s.top().first;
        }
        int getMin(){
            if(s.size()==0)
                return -1;
            return s.top().second;
        }
};



int main(){
    MinStack ms;
    ms.push(4);
    ms.push(3);
    ms.push(5);
    ms.push(2);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin();
    
}



// int getMin(){
// if(s.size() == 0){
// return -1;
// }
// else{
// return minElement;
// }
// }

// void push(int x){
//     if(s.size()==0){
//         s.push(x);
//         minElement = x;
//     }
//     else{
//         if(x>=minElement){
//             s.push(x);
//         }
//         else{
//             s.push(2*x-minElement);
//             minElement = x;
//         }
//     }
// }

// void pop(){
//     if(s.size()==0){
//         return;
//     }
//     else{
//         if(s.top() >= minElement){
//         s.pop();
//     }
//     else{
//         minElement = 2*minElement - s.top();
//         s.pop();
//     }
//     }
// }

// int top(){
//     if(s.size()==0){
//         return -1;
//     }
//     else{
//         if(s.top()>=minElement){
//             return s.top();
//         }
//         else{
//             return minElement;
//         }
//     }
// }