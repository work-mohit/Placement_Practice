/*
    PS :
        Hatori is the class teacher with 'N' students. 
        He wants to select some students for the Republic Day parade. 
        But out of all the students he chooses, the absolute difference of heights of any two students should not exceed 5.
        
    So this is kind of problem i didn't get understand easily although it is marked easy.
    so we need to return the max set of numbers whose diff of min and max element is less then 5 

    Let the heights of students be 'H' = {1, 6, 7, 8, 2, 3, 11}. 
    So at max, he can pick 4 students with heights: 6, 7, 8, and 11.

    Approach :
        we sort the elements that will look like: {1,2,3,6,7,8,11}
*/

int chooseMaxStudents(vector<int> &h, int n) {
    sort(h.begin(), h.end());     // this get done half of the job
    // two pointer technique 
    // front will stay at one element and back will move forward 
     
    // which is back -front + 1  and compare it with the 
    int front =0, back = 0 , len = INT_MIN;     

    while(back<n)               // if back pointer go out of array range i will stop 
    {
        while(h[back] - h[front] > 5)   // diff is > 5 then i have to decrease the diff which can be done by increasing the front pointer 
        {
            front++;
        }                            
        
        len = max(len, back-front+1);   // update length everytime 
        back++;
    }
    
    if(len == INT_MIN) // 
        return 0;
    return len;
    
}
