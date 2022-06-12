// https://leetcode.com/problems/shortest-path-in-binary-matrix/
/*
    Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix.
    If there is no clear path, return -1.

    A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0))
    to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

*/

class Solution {
public:
    // ye toh validity check krne ke liye hoga ki step lena bhi hai ya nhi
    bool isValid(vector<vector<int>>& grid, int i, int j,int n, vector<vector<bool>>& visited){
        return (i >= 0 and i < n and j >= 0 and j < n and grid[i][j]==0 and !visited[i][j]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));  // <== ye banalo visited wala agr ye nhi banana toh inplace change krna jb bhi visit krlo 1 kr dena
        queue<pair<int , int>> que; // kha hai ki bfs se kro toh queue toh use krni padegi 
        int ans = 0;
        int nodesPushed;            // accha ye hai current level ke nodes ka hisaab rakhne ko, jitna ye hoga utna loop chlega
        if(grid[0][0] == 0){
            que.push({0,0});           // ye thoda sa queue ko bhar lo agr first position valid hai agr nhi hogi toh que empty
            visited[0][0] = true;       // aur agr que empty ho gya toh while ka loop chalega hi nhi ... krlo fr kuch
        }

        while(!que.empty()){
            nodesPushed = que.size();
            ans++;                  // ye main hai har ek level me jaake ans ko increase kr do 
            
            for(int i = 0; i< nodesPushed; i++){
                pair<int, int> currCell = que.front();   
                que.pop();
                int x = currCell.first;
                int y = currCell.second;
                
                if(x == n-1 and y == n-1)   // ye toh last me agr pahuch gya toh ans ko turant bhej do 
                    return ans;
                
                for(int j = x-1; j <= x+1; j++){      // accha ye trick toh bahut best hai x-1 se x+1 (x-1 , x , x+1) teeno aagye
                    for(int k = y-1; k <= y+1; k++){
                        if(isValid(grid, j, k, n, visited)){ // check krna tbhi daalna 
                            que.push({j,k});
                            visited[j][k] = true;    // visited me bhi attendence lga dena uss pair ki 
                        }
                    }
                }
                
            }
            
        }
        return -1;
    }
};