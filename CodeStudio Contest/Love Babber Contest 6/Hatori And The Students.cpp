int chooseMaxStudents(vector<int> &h, int n) {
    sort(h.begin(), h.end());
    int front =0, back = 0 , len = INT_MIN;
    while(back<n)
    {
        while(h[back] - h[front] > 5)
        {
            front++;
        }
        len = max(len, back-front+1);   
        back++;
    }
    
    if(len == INT_MIN) 
        return 0;
    return len;
    
}
