#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pf push_front
#define mp make_pair
#define MAX_N 1e9
#define MIN_N -1e9
#define MAX_SIZE 1000000
#define PI 3.141592653589793238
#define pb push_back
#define sz(s) s.size()
const int mod = 1e9 + 7;
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll fibo[101];
char find(ll n, ll k)
{
    if (n == 1)
    {
        return 'A';
    }
    if (n == 2)
    {
        return 'B';
    }

    if (k <= fibo[n - 2])
    {
        return find(n - 2, k);
    }
    else
    {
        return find(n - 1, k - fibo[n - 2]);
    }
}
int main()
{
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i <= 92; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << find(n, k) << endl;
    }
    return 0;
}