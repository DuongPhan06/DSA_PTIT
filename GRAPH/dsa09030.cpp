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
int color[1001];
bool DFS(int u, int par)
{
    color[u] = 3 - color[par];
    for (int v : ke[u])
    {
        if (color[v] == 0)
        {
            if (!DFS(v, u))
            {
                return false;
            }
        }
        else if (color[u] == color[v])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(color, 0, sizeof(color));
        for (int i = 1; i <= n; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            ke[y].pb(x);
        }
        color[0] = 1;
        // Chay het tat ca thanh phan lien thong
        // Phai dung tat ca thanh phan lien thong moi la do thi hai phia
        bool check = true;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                if (!DFS(i, 0))
                {
                    check = false;
                }
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