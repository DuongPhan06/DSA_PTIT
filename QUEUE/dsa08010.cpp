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

void solve()
{
    int n;
    cin >> n;
    set<ll> se;
    int gtnn = 1e9;
    queue<pair<int, int>> q;
    q.push({n, 0});
    se.insert(n);
    while (!q.empty())
    {
        pair<ll, ll> x = q.front();
        q.pop();
        int a = x.fi, steps = x.se;
        if (steps >= gtnn)
        {
            continue;
        }
        if (a == 1)
        {
            gtnn = min(gtnn, steps);
            continue;
        }
        int x1 = a - 1;
        if (se.find(x1) == se.end() && x1 >= 0)
        {
            se.insert(x1);
            q.push({x1, steps + 1});
        }
        for (int i = 2; i <= sqrt(a); i++)
        {
            if (a % i == 0)
            {
                if (se.find(a / i) == se.end())
                {
                    q.push({a / i, steps + 1});
                    se.insert(a / i);
                }
            }
        }
    }
    cout << gtnn << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}