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
        ll gh = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            gh *= 10;
        }
        vector<ll> v;
        queue<ll> q;
        q.push(6);
        q.push(8);
        while (!q.empty())
        {
            ll x = q.front();
            cnt++;
            v.pb(x);
            q.pop();
            if (x >= gh)
            {
                break;
            }
            else
            {
                ll tmp1 = x * 10 + 6;
                ll tmp2 = x * 10 + 8;
                if (tmp1 < gh)
                {
                    q.push(tmp1);
                }
                if (tmp2 < gh)
                {
                    q.push(tmp2);
                }
            }
        }
        cout << cnt << endl;
        reverse(v.begin(), v.end());
        for (ll x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}