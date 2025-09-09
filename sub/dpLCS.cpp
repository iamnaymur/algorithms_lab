#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    int dp[101][101]; // table for bottom-up DP

    // Fill table
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // base case: empty string
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // last chars match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // no match
        }
    }

    return dp[m][n]; // final LCS length
}

int main()
{
    string X, Y;
    cin >> X >> Y;

    cout << "Length of LCS: " << LCS(X, Y) << endl;
    return 0;
}
