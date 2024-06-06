//*https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//^ APPROACH 1 - RECURSION
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        if (n == 0 || W == 0)
            return 0; // base condition

        if (wt[n - 1] <= W)
        {
            return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        }
        else if (wt[n - 1] > W)
        {
            return knapSack(W, wt, val, n - 1);
        }
    }
};