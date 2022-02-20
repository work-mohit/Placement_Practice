// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-10/problems/16711

int count(int N, string S)
{
    unordered_set<int> ans;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    ans.insert(0);
    for (int i = 0; i < N; ++i)
    {

        // Checking if it is your turn or yours friend's turn.
        if (i % 2 == 0)
        {

            // You move UP.
            if (S[i] == 'U')
            {
                x1--;
            }

            // You move DOWN.
            else if (S[i] == 'D')
            {
                x1++;
            }

            // You move LEFT.
            else if (S[i] == 'L')
            {
                y1--;
            }

            // You move RIGHT.
            else
            {
                y1++;
            }

            // Compressing the point and then adding it to the answer.
            ans.insert((x1 * 1e6) + y1);
        }
        else
        {
            // Your friend moves UP.
            if (S[i] == 'U')
            {
                x2--;
            }

            // Your friend moves DOWN.
            else if (S[i] == 'D')
            {
                x2++;
            }

            // Your friend moves LEFT.
            else if (S[i] == 'L')
            {
                y2--;
            }

            // Your friend moves RIGHT.
            else
            {
                y2++;
            }

            // Compressing the point and then adding it to the answer.
            ans.insert((x2 * 1e6) + y2);
        }
    }
    return ans.size();
}