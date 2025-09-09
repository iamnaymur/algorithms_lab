#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll B, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return B;

    ll P = power(B, n / 2);

    if (n % 2 == 0) // n is even
        return P * P;
    else // n is odd
        return B * P * P;
}

int main()
{
    ll B;
    int n;
    cout << "Enter base B and exponent n: ";
    cin >> B >> n;

    cout << power(B, n) << endl;
    return 0;
}
