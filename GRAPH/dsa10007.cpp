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
// Cây khung thì đồ thị phải liên thông, không có chu trình và phải đi đầy đủ hết các đỉnh
vector<int> ke[10001];
bool used[10001];
int cnt, n, m;
vector<pair<int, int>> ans;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int v : ke[x])
        {
            if (!used[v])
            {
                used[v] = true;
                ans.pb({x, v});
                q.push(v);
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
        int n, m, u;
        cin >> n >> m >> u;
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            ke[i].clear();
        }
        memset(used, false, sizeof(used));
        cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            ke[y].pb(x);
        }
        BFS(u);
        if (ans.size() == n - 1)
        {
            for (auto it : ans)
            {
                cout << it.fi << " " << it.se << endl;
            }
        }
        else
            cout << -1 << endl;
    }
    return 0;
}