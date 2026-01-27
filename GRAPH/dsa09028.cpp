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

vector<int> ke[1001];
int color[1001];
int v, e, n;

bool check(int u, int c)
{
    for (int v : ke[u])
    {
        if (color[v] == c)
        {
            return false;
        }
    }
    return true;
}

bool solve(int u)
{
    if (u > v)
    {
        return true;
    }
    for (int c = 1; c <= n; c++)
    {
        if (check(u, c))
        {
            color[u] = c;
            if (solve(u + 1))
            {
                return true;
            }
        }
        color[u] = 0;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e >> n;
        memset(color, 0, sizeof(color));
        for (int i = 1; i <= v; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            ke[y].pb(x);
        }
        if (solve(1))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}