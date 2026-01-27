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
int d[1000001];
int gtln = -1e9;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = true;
    d[u] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int v : ke[x])
        {
            if (!used[v])
            {
                used[v] = true;
                q.push(v);
                d[v] = d[x] + 1;
                gtln = max(gtln, d[v]);
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
        int n;
        cin >> n;
        gtln = -1e9;
        memset(used, false, sizeof(used));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            ke[y].pb(x);
        }
        BFS(1);
        cout << gtln << endl;
    }
    return 0;
}