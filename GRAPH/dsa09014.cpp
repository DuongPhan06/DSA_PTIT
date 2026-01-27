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
bool used[1001];
int parent[1001];
int check = 0;
void DFS(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            parent[v] = u;
            DFS(v);
        }
        else
        {
            if (v != parent[u])
            {
                check = 1;
                return;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        check = 0;
        int v, e;
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
        for (int i = 1; i <= v; i++)
        {
            if (!used[i])
            {
                DFS(i);
            }
        }
        if (check)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}