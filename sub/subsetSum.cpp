#include <bits/stdc++.h>
using namespace std;

// Check if partial sum meets the target
// return 0 → exact sum found
// return 1 → sum exceeded target
// return -1 → still less than target
int checkSum(vector<int> &A, int T, int r)
{
    int sum = 0;
    for (int i = 0; i <= r; i++)
        sum += A[i];
    if (sum == T)
        return 0;
    else if (sum > T)
        return 1;
    else
        return -1;
}

// Recursive SubsetSum
bool SubSetSum(vector<int> &A, vector<int> &X, int T, int r, int i)
{
    int n = X.size();
    if (r == n)
        return false;

    for (int j = i; j < n; j++)
    {
        A[r] = X[j]; // choose element X[j]

        int s = checkSum(A, T, r);

        if (s == 0)
        {
            for (int k = 0; k <= r; k++)
                cout << A[k] << " ";
            cout << "\n";
            return true;
        }
        else if (s == 1)
            continue; // sum exceeded → skip

        else if (s == -1)
        {
            bool success = SubSetSum(A, X, T, r + 1, j + 1);
            if (success)
                return true;
        }
    }
    return false;
}

int main()
{
    int n, T;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> X(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> X[i];
    cout << "Enter target sum: ";
    cin >> T;

    vector<int> A(n, 0);

    if (!SubSetSum(A, X, T, 0, 0))
        cout << "No subset found.\n";

    return 0;
}
