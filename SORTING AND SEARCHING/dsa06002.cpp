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

int a[1000001];
bool cmp(pair<int, int> pa1, pair<int, int> pa2)
{
    if (pa1.se != pa2.se)
    {
        return pa1.se < pa2.se;
    }
    else
    {
        return pa1.fi < pa2.fi;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<int, int>> pa;
        for (int i = 0; i < n; i++)
        {
            pa.pb(make_pair(i, abs(k - a[i])));
        }
        sort(pa.begin(), pa.end(), cmp);
        for (int i = 0; i < pa.size(); i++)
        {
            cout << a[pa[i].fi] << " ";
        }
        cout << endl;
    }
    return 0;
}