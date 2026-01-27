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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            q.push(a[i]);
        }
        ll ans = 0;
        while (q.size() > 1)
        {
            ll x = q.top();
            q.pop();
            ll y = q.top();
            q.pop();
            ll tmp = x + y;
            tmp %= mod;
            ans = (ans + tmp) % mod;
            q.push(tmp);
        }
        cout << ans << endl;
    }
    return 0;
}