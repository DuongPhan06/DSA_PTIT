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

// 2: Có chu trình Euler (Eulerian cycle) - tất cả đỉnh bậc chẵn và phải liên thông
// 1: Có đường đi Euler (Eulerian path) - đúng 2 đỉnh bậc lẻ và phải liên thông
// 0: Không có đường đi/chu trình Euler

vector<int> ke[1001];
bool used[1001];
int parent[1001];
int v, e;
void DFS(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (used[v] == false)
        {
            DFS(v);
            used[v] = true;
        }
    }
}
int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!used[i])
        {
            DFS(i);
            cnt++;
        }
    }
    return cnt;
}
int check()
{
    if (tplt() > 1)
    {
        return 0;
    }
    int odd = 0;
    for (int i = 1; i <= v; i++)
    {
        if (ke[i].size() % 2 == 1)
        {
            odd++;
        }
    }
    if (odd == 0)
    {
        return 2;
    }
    else if (odd <= 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        memset(used, false, sizeof(used));
        memset(parent, 0, sizeof(parent));
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
        cout << check() << endl;
    }
    return 0;
}