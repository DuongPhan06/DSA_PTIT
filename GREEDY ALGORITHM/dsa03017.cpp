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
        string s;
        cin >> s;
        map<char, ll> mp;
        priority_queue<ll> q;
        for (char x : s)
        {
            mp[x]++;
        }
        for (auto x : mp)
        {
            q.push(x.se);
        }
        ll ans = 0;
        while (n--)
        {
            ll x = q.top();
            q.pop();
            x--;
            q.push(x);
        }

        while (q.size() > 0)
        {
            ll x = pow(q.top(), 2);
            ans += x;
            q.pop();
        }
        cout << ans << endl;
    }
    return 0;
}