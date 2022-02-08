#include<bits/stdc++.h>
#include <chrono>
using namespace std;
 void printmatrix(std::vector<std::vector<int>>& matrix){
    std::cout<<"The Matrix is :"<<std::endl<<std::endl;
    for(auto x : matrix){
        for(auto y : x)
            std::cout<<y<<" ";
        std::cout<<std::endl;
     }
     std::cout<<std::endl;
 }
 void rotate(std::vector<std::vector<int>>& m) {
//       Method 1
    // int n = matrix.size();
    // int a = 0;
    // int b = n-1;
    // while(a<b){
    //     for(int i=0;i<(b-a);++i){   
    //         swap(matrix[a][a+i], matrix[a+i][b]); //(0,0)=> (0,2), 
    //         swap(matrix[a][a+i], matrix[b][b-i]);  //(0,0)=>(2,2)
    //         swap(matrix[a][a+i], matrix[b-i][a]);   // (0,0)=>(2,0)
    //     }
    //     ++a;
    //     --b;
    // }
//       Method 2
    int n = m.size();

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            swap(m[i][j], m[j][i]);

    for(int i=0; i<n; i++)
        reverse(m[i].begin(), m[i].end());

       
}
int main (){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    std::vector<std::vector<int>> matrix = {{3,4,5},
                            {6,7,8},
                            {1,2,9}};
    printmatrix(matrix);
    std::cout<<"After rotation:";


    auto t1 = high_resolution_clock::now();
    rotate(matrix);
    auto t2 = high_resolution_clock::now();
    
    printmatrix(matrix);

    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    std::cout <<"Total time take by the function is " <<ms_int.count() << "ms\n";


    duration<double, std::milli> ms_double = t2 - t1;

    std::cout <<"Total time take by the function is "<< ms_double.count() << "ms\n";


    return 0;
}