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

int parent[1001], sz[1001];
bool used[1001];
struct canh
{
    int u, v, w;
};
int n, m;
vector<canh> dscanh;

int Find(int u)
{
    while (u != parent[u])
    {
        u = parent[u];
    }
    return u;
}

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
        parent[u] = v;
        sz[v] += sz[u];
    }
    else
    {
        parent[v] = u;
        sz[u] += sz[v];
    }
    return true;
}
bool cmp(canh a, canh b)
{ // Sap xep tang dan gia tri
    return a.w < b.w;
}
void Kruskal()
{
    sort(dscanh.begin(), dscanh.end(), cmp);
    ll d = 0;
    vector<canh> mst;
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1) // n - 1 canh
        {
            break;
        }
        if (Union(dscanh[i].u, dscanh[i].v))
        {
            d += dscanh[i].w;
            mst.pb(dscanh[i]);
        }
    }
    cout << d << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        dscanh.clear();
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));
        for (int i = 1; i <= m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            dscanh.pb({x, y, w});
        }
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        Kruskal();
    }
    return 0;
}