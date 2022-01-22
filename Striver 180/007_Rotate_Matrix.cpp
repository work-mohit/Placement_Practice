 void rotate(vector<vector<int>>& matrix) {
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