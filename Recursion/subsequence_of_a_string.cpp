// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0

void solve(vector<string>& res, string str, string output, int index){
    //base case 
   
    if ( index >= str.length()){

        if (output.length() > 0)
        	res.push_back(output);
        return;
    }
    // exclude 
    solve(res, str,output, index+1);
    // include
    char s = str[index];
    output.push_back(s);
    solve(res,str,output, index+1);
}
void solveBySubstr(vector<string>& res, string str, string output){
    if(str.empty()){
        res.push_back(output);
        return;
    }
    solve(res, str.substr(1), output); // exclude

    output += str[0];
    solve(res, str.substr(1), output);

}
vector<string> subsequences(string str){
	// Write your code here
    vector<string> res;
    string output = "";
    int index = 0;
    // solve(res, str, output, index);
    solveBySubstr(res,str,output);
	return res;
}
