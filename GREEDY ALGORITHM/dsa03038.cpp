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

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.se < y.se;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> pa;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            pa.pb({x, y});
        }
        sort(pa.begin(), pa.end(), cmp);
        int cnt = 1;
        int end = pa[0].se;
        for (int i = 1; i < n; i++)
        {
            if (pa[i].fi >= end)
            {
                cnt++;
                end = pa[i].se;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
