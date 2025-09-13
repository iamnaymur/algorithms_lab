#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int idx, int maxWeight)
{
    if (idx < 0 || maxWeight <= 0)
        return 0;

    if (dp[idx][maxWeight] != -1)
        return dp[idx][maxWeight];

    if (weight[idx] <= maxWeight)
    {
        int opt1 = knapsack(idx - 1, maxWeight - weight[idx]) + val[idx];
        int opt2 = knapsack(idx - 1, maxWeight);
        dp[idx][maxWeight] = max(opt1, opt2);
        return dp[idx][maxWeight];
    }
    else
    {
        dp[idx][maxWeight] = knapsack(idx - 1, maxWeight);
        return dp[idx][maxWeight];
    }
}

int main()
{

    int n, maxWeight;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> maxWeight;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= maxWeight; j++)
            dp[i][j] = -1;

    cout << knapsack(n - 1, maxWeight) << endl;
    return 0;
}