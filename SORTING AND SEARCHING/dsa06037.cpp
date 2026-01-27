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
int l[1000001];
int r[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<int> v;
        l[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            l[i] = max(l[i - 1], a[i]);
        }
        r[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
        {
            r[i] = min(r[i + 1], a[i]);
        }
        int cnt = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            int x = l[i];
            int y = r[i + 1];
            if (x <= y)
            {
                cnt++;
                v.pb(i);
            }
        }
        cout << cnt << endl;
        if (v.size() > 0)
        {
            for (int x : v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}