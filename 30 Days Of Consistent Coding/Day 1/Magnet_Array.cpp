// https://practice.geeksforgeeks.org/problems/magnet-array-problem3743/1#


double getForce(int n, double M[], double l , double h){
    while(h-l >= 0.000001){
        double mid = (l + h)/2;
        double totalforce = 0;
        
        double left = 0.00,right = 0.00;
        for(int i=0; i<n; i++) {
            if(i <= l) 
                right += 1.0/(mid-M[i]);
            else
                left += 1.0/(M[i]-mid);
        }
        if(left < right)
            l = mid;
        else
            h = mid;
    }
    return l;
}
void nullPoints(int n, double magnets[], double getAnswer[])
{
    for(int i = 0; i < n-1; i++){
        getAnswer[i] = getForce(n, magnets, magnets[i] , magnets[i+1]);
    }
}


//////////////////////////////////////////////////
// copied the comment from which i take help to solve this problem 
/// Explanation of the problem

// So I will explain the equilibrium concept for the second example:
// [0, 10, 20, 30]

//     ^
// We will find the equilibrium for 1st place i. e. between 0 and 10:

// low = 0, high = 10, Mid = 5;
// So calculate the left forces and right forces at point 5.
// left forces = 1/(5 - 0) => (0.25)
// Right forces = 1/(10-5) + 1/(20 - 5) + 1/(20-5) => (0.306)
// Clearly, left forces < right forces:

// So, we move left


// Now, low = 0, high = 5, Mid = 2.5;
// So calculate the left forces and right forces at point 2.5.
// left forces = 1/(2.5 - 0) => (0.4)
// Right forces = 1/(10-2.5) + 1/(20 - 2.5) + 1/(20-2.5) => (0.22)
// Clearly, left forces > right forces:

// So, we Move Right

// Now, low = 2.5, high = 5, Mid = 3.75;
// So calculate the left forces and right forces at point 3.75.
// left forces = 1/(3.75 - 0) => (0.26)
// Right forces = 1/(10-3.75) + 1/(20 - 3.75) + 1/(20-3.75) => (0.25)
// Clearly, left forces > right forces:

// So, we Move Right
//  Follow this till we get 
// Right forces == Left forces.
// and calculate the same for all the equilibrium points.