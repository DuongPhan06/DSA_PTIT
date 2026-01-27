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

ll a[1000001];
ll search1(ll a[], ll n, ll bd, ll val)
{
    ll l = bd;
    ll r = n - 1;
    ll index = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (a[mid] < val)
        {
            index = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return index;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ll r = search1(a, n, i + 1, k + a[i]);
            if (r != -1)
            {
                ans += (r - i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}