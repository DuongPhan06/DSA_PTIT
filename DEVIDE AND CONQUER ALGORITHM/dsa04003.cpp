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

// Số các dãy số nguyên dương có tổng bằng n sẽ là 2^(n - 1);
const int m = 123456789;
ll binpow(ll n)
{
    if (n == 1)
    {
        return 2;
    }
    ll x = binpow(n / 2);
    x = (x * x) % m;
    if (n % 2 == 1)
    {
        return (x * 2) % m;
    }
    return x;
}
void solve()
{
    ll n;
    cin >> n;
    cout << binpow(n - 1) << endl;
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