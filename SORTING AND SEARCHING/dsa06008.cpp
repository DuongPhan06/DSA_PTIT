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

int cnt[5];
int upper(vector<int> &b, int bd, int val)
{
    int l = bd;
    int r = b.size() - 1;
    int index = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid] > val)
        {
            index = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return index;
}
ll demSL(vector<int> &b, int m, int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return cnt[0];
    }
    int dem = cnt[0] + cnt[1];
    int it = upper(b, 0, x);
    if (it != -1)
    {
        dem += (m - it);
    }
    if (x == 2)
    {
        dem = dem - cnt[3] - cnt[4];
    }
    if (x == 3)
    {
        dem += cnt[2];
    }
    return dem;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(cnt, 0, sizeof(cnt));
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] <= 4)
            {
                cnt[b[i]]++;
            }
        }
        sort(b.begin(), b.end());
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += demSL(b, m, a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}