class Solution{
    private:
    // isSafe checks the next move is valid or not.
    // thee condition we need to check 
    //      1. should be under array range 0 to n.
    //      2. visited should be 0 (means not already visited)
    //      3. the next movement should be valid (means maze[newx][newy]== 1).
        bool isSafe(int newx ,int newy , int n , vector<vector<int>> &visited ,vector<vector<int>> &maze){
            if((newx >= 0 && newx < n) && (newy>=0 && newy < n) && visited[newx][newy] == 0 && maze[newx][newy] == 1){
                return true;
            }
            else{
                return false;
            }
                
        }


        void solve(vector<vector<int>> &maze, vector<string>& paths,int n,vector<vector<int>> &visited,string& currPath, int posx , int posy){
            // base case if we reach (n-1,n-1) then stores path and return.
            if(posx == n-1  && posy == n-1){
                paths.push_back(currPath);
                return;
            }
            // mark as visited
            visited[posx][posy] = 1;
            
            int newx = posx+1;
            int newy = posy;
            if(isSafe(newx,newy, n, visited, maze)){   // check isSafe 
                currPath.push_back('D');                // push path
                solve(maze,paths,n,visited, currPath , newx, newy); // go to path 
                currPath.pop_back();                        // backtrack 
            }
            
            newx = posx-1;
            newy = posy;
            if(isSafe(newx,newy, n, visited, maze)){
                currPath.push_back('U');
                solve(maze, paths,n, visited,currPath , newx, newy);
                currPath.pop_back();
            }
            
            newx = posx;
            newy = posy-1;
            if(isSafe(newx,newy, n, visited, maze)){
                currPath.push_back('L');
                solve(maze, paths,n, visited,currPath , newx, newy);
                currPath.pop_back();
            }
            
            newx = posx;
            newy = posy+1;
            if(isSafe(newx,newy, n, visited, maze)){
                currPath.push_back('R');
                solve(maze, paths,n, visited,currPath , newx, newy);
                currPath.pop_back();
            }
          
            // unmark as visited 
            // so that when we return there will be no conflicts to other paths.
            visited[posx][posy] = 0;
        }
    public:
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> paths;
        if(maze[0][0] == 0)
            return paths;
        string currPath = "";
        
        vector<vector<int>> visited(n,vector<int>(n,0));   
        
        solve(maze,paths,n,visited,currPath,0, 0);
        
        sort(paths.begin(), paths.end());
        return paths;
    }
};
