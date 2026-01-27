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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                if (a[i] + a[l] + a[r] < k)
                {
                    ans += (r - l);
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}