// General divide and conquer method

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll multiplication(ll x, ll y, ll n)
{
    if (n == 1)
        return x * y;

    int m;
    if (n % 2 == 1)
        m = ceil(n / 2);
    else
        m = n / 2;

    ll p = pow(10, m);

    ll a = x / p;
    ll b = x % p;
    ll c = y / p;
    ll d = y % p;

    ll e = multiplication(a, c, m);
    ll f = multiplication(a, d, m);
    ll g = multiplication(b, c, m);
    ll h = multiplication(b, d, m);

    return (ll)pow(10, 2 * m) * e + (ll)pow(10, m) * (f + g) + h;
}
int main()
{
    ll x, y;
    cin >> x >> y;

    int n = max((int)to_string(x).size(), (int)to_string(y).size());
    ll result = multiplication(x, y, n);
    cout << result << endl;
    return 0;
}

// Karatsuva method
/* #include <bits/stdc++.h>
#define ll long long
using namespace std;

ll multiplication(ll x, ll y, ll n)
{
    if (n == 1)
        return x * y;

    ll m = (n % 2 == 1) ? (n + 1) / 2 : n / 2;
    ll p = pow(10, m);

    ll a = x / p;
    ll b = x % p;
    ll c = y / p;
    ll d = y % p;

    ll e = multiplication(a, c, m);
    ll f = multiplication(b, d, m);
    ll k = multiplication(a - b, c - d, m);

    return (ll)pow(10, 2 * m) * e +
           (ll)pow(10, m) * (e + f - k) +
           f;
}

int main()
{
    ll x, y;
    cin >> x >> y;

    int n = max((int)to_string(x).size(), (int)to_string(y).size());
    ll result = multiplication(x, y, n);
    cout << result << endl;
    return 0;
}
 */