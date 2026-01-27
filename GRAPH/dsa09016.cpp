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
int degree[1001]; // Tính bán bậc vào
int v, e;
int color[1001];
bool DFS(int u)
{
    color[u] = 1;
    for (int v : ke[u])
    {
        if (color[v] == 0)
        {
            if (DFS(v))
            {
                return true;
            }
        }
        else if (color[v] == 1)
        {
            return true;
        }
    }
    color[u] = 2;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        memset(used, false, sizeof(used));
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
        }
        bool check = false;
        for (int i = 1; i <= v; i++)
        {
            if (color[i] == 0)
            {
                if (DFS(i))
                {
                    check = true;
                    break;
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