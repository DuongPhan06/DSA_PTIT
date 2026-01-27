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
int v, e;
int dem = 0;
bool check = false;
void DFS(int u, int cnt)
{
    if (cnt == v)
    {
        check = true;
    }
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            DFS(v, cnt + 1);
        }
    }
    used[u] = false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        memset(used, false, sizeof(used));
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
        bool ok = false;
        for (int i = 1; i <= v; i++)
        {
            memset(used, false, sizeof(used));
            check = false;
            DFS(i, 1);
            if (check)
            {
                ok = true;
            }
        }
        if (ok)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}