#include <bits/stdc++.h>
using namespace std;

int recurDistance(string &S, string &T, int m, int n)
{
    if (m == 0)
        return n; // Need n insertions
    if (n == 0)
        return m; // Need m deletions

    if (S[m - 1] == T[n - 1])
    {
        return recurDistance(S, T, m - 1, n - 1); // No operation needed
    }

    return 1 + min({
                   recurDistance(S, T, m - 1, n),    // Delete
                   recurDistance(S, T, m, n - 1),    // Insert
                   recurDistance(S, T, m - 1, n - 1) // Replace
               });
}

int main()
{
    string S, T;
    cin >> S >> T;

    int m = (int)S.size();
    int n = (int)T.size();

    cout << "Edit Distance (recursive): " << recurDistance(S, T, m, n) << endl;

    return 0;
}
