#include <bits/stdc++.h>
using namespace std;

int C[101][101];

int nCr(int n, int r)
{

    if (r == 0 || r == n)
        return 1;

    if (C[n][r] != -1)
        return C[n][r];

    C[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);

    return C[n][r];
}

int main()
{

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            C[i][j] = -1;

    int n, r;
    cin >> n >> r;

    int result = nCr(n, r);
    cout << result << endl;

    return 0;
}
