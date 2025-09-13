// only using recursion
/* #include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int i, int j)
{
    if (a[i] == '\0' || b[j] == '\0')
        return 0;
    if (a[i] == b[j])
        return 1 + lcs(a, b, i + 1, j + 1);
    else
        return max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
}

int main()
{
    string a = "ABCBDAB";
    string b = "BDCABA";
    cout << lcs(a, b, 0, 0) << endl;
    return 0;
} */

//  using recursion with memoization
/* #include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcs(string &a, string &b, int i, int j)
{
    if (a[i] == '\0' || b[j] == '\0')
        return 0;

    // check if its already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        dp[i][j] = 1 + lcs(a, b, i + 1, j + 1);
    else
        dp[i][j] = max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));

    return dp[i][j];
}

int main()
{

    string a = "ABCBDAB";
    string b = "BDCABA";
    memset(dp, -1, sizeof(dp));
    cout << lcs(a, b, 0, 0) << endl;
    return 0;
} */

// Using dp TABULATION BOTTOM UP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "ABCBDAB";
    string b = "BDCABA";
    int m = a.size();
    int n = b.size();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "Length of LCS = " << dp[m][n] << endl;

    return 0;
}
