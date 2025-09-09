// recursive implementation for fibonacci
/* #include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    cin >> n;

    int result = fib(n);
    cout << result << endl;
    return 0;
} */

// With memoization technique
#include <bits/stdc++.h>
using namespace std;

int F[101];

int fibo(int n)
{
    if (n <= 1)
        return n;

    if (F[n] != -1)
        return F[n];

    F[n] = fibo(n - 1) + fibo(n - 2);
    return F[n];
}

int main()
{
    for (int i = 0; i < 101; i++)
        F[i] = -1;

    int n;
    cin >> n;

    int result = fibo(n);
    cout << result << endl;
    return 0;
}