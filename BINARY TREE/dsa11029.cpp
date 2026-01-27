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

vector<int> adj[1001];
int parent[1001];
bool used[1001];
vector<int> leaf;
void DFS(int u)
{
    used[u] = true;
    for (int v : adj[u])
    {
        if (!used[v])
        {
            used[v] = true;
            parent[v] = u;
            DFS(v);
        }
    }
}

void path(int u, int v)
{
    vector<int> ans;
    while (u != v)
    {
        ans.pb(v);
        v = parent[v];
    }
    ans.pb(u);
    reverse(ans.begin(), ans.end());
    for (int x : ans)
    {
        cout << x << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        leaf.clear();
        memset(used, false, sizeof(used));
        memset(parent, 0, sizeof(parent));
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() == 1)
            {
                leaf.pb(i);
            }
        }
        DFS(1);
        for (int x : leaf)
        {
            if (x == 1)
            {
                continue;
            }
            path(1, x);
            cout << endl;
        }
    }
    return 0;
}