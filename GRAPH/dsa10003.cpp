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

int parent[1001];
int sz[1001];
// Di tim dai dien
// int Find(int u)
// {
//     while (u != parent[u])
//     {
//         u = parent[u];
//     }
//     return u;
// }
int Find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    else
    {
        return parent[u] = Find(parent[u]);
    }
}
// bool Union(int u, int v)
// {
//     u = Find(u);
//     v = Find(v);
//     if (u == v)
//     {
//         return false;
//     }
//     else if (u < v)
//     {
//         parent[v] = u;
//     }
//     else
//     {
//         parent[u] = v;
//     }
//     return true;
// }
bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
    {
        return false;
    }
    if (sz[u] < sz[v])
    {
        parent[v] = u;
        sz[u] += sz[v];
    }
    else
    {
        parent[u] = v;
        sz[v] += sz[u];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        bool check = false;
        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= v; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            if (Union(x, y) == false)
            {
                check = true;
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