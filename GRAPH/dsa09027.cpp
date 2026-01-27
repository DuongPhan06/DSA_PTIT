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

bool used[1001];
vector<int> ke[1001];
void DFS(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            used[v] = true;
            DFS(v);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(ke, 0, sizeof(ke));
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            ke[y].pb(x);
        }
        int q;
        cin >> q;
        while (q--)
        {
            memset(used, 0, sizeof(used));
            int s, t;
            cin >> s >> t;
            DFS(s);
            if (used[t] == false)
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
    }
    return 0;
}