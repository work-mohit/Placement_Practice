class Solution {
public:
    string reorganizeString(string s) {
        string new_s;
        int n = s.size();
        unordered_map<char , int> umap;
        
        // making map
        for(int i = 0; i< s.size(); i++){
            umap[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto &x : umap){
            pq.push(make_pair(x.second, x.first));
        }
        
        while(pq.size()> 1){
            // dono max frequent character nikaal lo 
            pair<int, char> top1 = pq.top();
            // agr aadhe ek 1 jyada se kisi ki frequency hai toh sambhav nhi hai mitrr, mna krdo 
            if(top1.first > (n + 1)/2)
                return "";
            pq.pop();
            pair<int, char> top2 = pq.top();
            pq.pop();
            
            // dono ko ek ek baar string me daal do;
            
            new_s += top1.second;
            new_s += top2.second;
            
            // dono ki mapping se count decreament krdo 
            umap[top1.second]--;
            umap[top2.second]--;
            
            // aur agr abhi 0 nhi huye hai toh heap ke andr daal do 
            
            if(umap[top1.second] > 0)
                pq.push(make_pair(umap[top1.second], top1.second));
            
            if(umap[top2.second] > 0)
                pq.push(make_pair(umap[top2.second], top2.second));
            
        }
        
        if(!pq.empty()){
            pair<int, char> last = pq.top();
            if(last.first > 1)
                return "";
            new_s += last.second;
        }
    
        return new_s;
    }
};