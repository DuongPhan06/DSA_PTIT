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
int dp[1000001];
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        ll n, k;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] %= k;
        }
        map<int, int> mp;
        int ans = -1e9;
        int sum = 0;
        int cnt = 0;
        int dem = 0;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                cnt++;
            }
            else
            {
                v.pb(a[i]);
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            sum += a[i];
            int x = sum % k;
            if (mp.count(x))
            {
                ans = max(ans, i - mp[x] + 1);
            }
            else
            {
                mp[x] = i;
            }
        }
        cout << ans + cnt << endl;
    }
    return 0;
}