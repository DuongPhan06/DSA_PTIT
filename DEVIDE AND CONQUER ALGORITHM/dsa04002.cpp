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

ll reverse(ll n)
{
    ll tmp = 0;
    while (n != 0)
    {
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}
ll binpow(ll a, ll b)
{
    if (b == 1)
    {
        return a % mod;
    }
    ll x = binpow(a, b / 2);
    x = (x * x) % mod;
    if (b % 2 == 0)
    {
        return x;
    }
    else
    {
        return (x * a) % mod;
    }
}

void solve()
{
    ll n;
    cin >> n;
    cout << 1ll * binpow(n, reverse(n)) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}