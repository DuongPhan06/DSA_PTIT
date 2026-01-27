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

ll check1(vector<ll> &a, ll n, ll bd, ll val)
{
    int l = bd;
    int r = n - 1;
    int idx = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == val)
        {
            idx = mid;
            r = mid - 1;
        }
        else if (a[mid] < val)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return idx;
}
ll check2(vector<ll> &a, ll n, ll bd, ll val)
{
    int l = bd;
    int r = n - 1;
    int idx = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == val)
        {
            idx = mid;
            l = mid + 1;
        }
        else if (a[mid] < val)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return idx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            ll pos1 = check1(a, n, i + 1, k - a[i]);
            ll pos2 = check2(a, n, i + 1, k - a[i]);
            if (pos1 != -1 && pos2 != -1)
            {
                if (pos1 == pos2)
                {
                    cnt++;
                }
                else
                {
                    cnt += (pos2 - pos1 + 1);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}