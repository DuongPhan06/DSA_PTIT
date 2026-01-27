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
        ll n;
        cin >> n;
        queue<ll> q;
        q.push(1);
        int cnt = 0;
        while (!q.empty())
        {
            ll x = q.front();
            q.pop();
            if (x <= n)
            {
                cnt++;
                ll tmp1 = x * 10;
                ll tmp2 = x * 10 + 1;
                if (tmp1 <= n)
                {
                    q.push(tmp1);
                }
                if (tmp2 <= n)
                {
                    q.push(tmp2);
                }
            }
            else
            {
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}