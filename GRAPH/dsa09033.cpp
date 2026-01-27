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

vector<int> ke[100001];
bool used[100001];
int n, m, cnt;
void DFS(int u)
{
    cnt++;
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
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
        memset(used, false, sizeof(used));
        cin >> n >> m;
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
        bool check = true;
        // Có nghĩa là số lần đi mỗi đỉnh đều phải thăm hết các đỉnh khác
        for (int i = 1; i <= n; i++)
        {
            memset(used, false, sizeof(used));
            cnt = 0;
            DFS(i);
            if (cnt != n)
            {
                check = false;
                break;
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