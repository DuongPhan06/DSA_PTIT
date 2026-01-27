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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 5), b(n + 5);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        sort(b.begin() + 1, b.begin() + n + 1, greater<ll>());
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += (1ll * a[i] * b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}