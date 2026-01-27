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

typedef pair<int, int> ii;
vector<pair<int, int>> ke[1001];
int v, e, s;
int d[1001];
bool used[1001];
void Dijkstra(int s)
{
    for (int i = 1; i <= v; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    used[s] = true;
    while (!q.empty())
    {
        ii x = q.top();
        q.pop();
        int dis = x.fi;
        int u = x.se;
        if (dis > d[u])
        {
            continue;
        }
        dis = d[u];
        for (ii it : ke[u])
        {
            int v = it.fi;
            int w = it.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(d, 0, sizeof(d));
        memset(used, false, sizeof(used));
        cin >> v >> e >> s;
        for (int i = 1; i <= v; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            ke[x].pb({y, w});
            ke[y].pb({x, w});
        }
        Dijkstra(s);
    }
    return 0;
}