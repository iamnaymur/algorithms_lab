#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int editDistance(string &a, string &b, int i, int j)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = editDistance(a, b, i - 1, j - 1);

    else
    {
        int insertOp = 1 + editDistance(a, b, i, j - 1);
        int deleteOp = 1 + editDistance(a, b, i - 1, j);
        int replaceOp = 1 + editDistance(a, b, i - 1, j - 1);
        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
}

int main()
{
    string a = "sunday";
    string b = "saturday";

    memset(dp, -1, sizeof(dp));

    cout << "Edit Distance = " << editDistance(a, b, a.size() - 1, b.size() - 1) << endl;

    return 0;
}
