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

ll check(ll n)
{
    string s = to_string(n);
    return s.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<ll> q;
        q.push(6);
        q.push(8);
        set<ll, greater<ll>> se;
        while (!q.empty())
        {
            ll x = q.front();
            q.pop();
            if (check(x) > n)
            {
                break;
            }
            else
            {
                se.insert(x);
                ll tmp1 = x * 10 + 6;
                ll tmp2 = x * 10 + 8;
                if (check(tmp1) <= n)
                {
                    q.push(tmp1);
                }
                if (check(tmp2) <= n)
                {
                    q.push(tmp2);
                }
            }
        }
        for (auto x : se)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}