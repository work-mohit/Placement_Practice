// added here link of the problem 

int sortArray(int N, vector<int> A)
{
    vector<vector<int>> O(N + 1, vector<int>(2, N + 1));

    // Storing the first and the last occurence of each integer.
    for (int i = 0; i < N; ++i)
    {
        O[A[i]][0] = min(O[A[i]][0], i);
        O[A[i]][1] = i;
    }
    int ans = 0, tot = 0, last = N + 1, ctr = 0;
    for (int i = N; i > 0; i--)
    {

        // Checking if the integer 'i' is present in the array or not.
        if (O[i][0] != N + 1)
        {
            ctr++;

            // Checking if the last occurrence of integer 'i' comes before the first occurrence of
            // the integer 'j' that is just greater than integer 'i'.
            if (O[i][1] < last)
            {
                tot++;
                ans = max(ans, tot);
                last = O[i][0];
            }
            else
            {
                tot = 1;
                last = O[i][0];
            }
        }
    }

    // Total number of distinct integers - maximum number of distinct integers that we do not move.
    return ctr - ans;
}