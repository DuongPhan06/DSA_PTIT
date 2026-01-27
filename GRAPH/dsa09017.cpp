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
void DFS(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            used[v] = true;
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
        int n;
        cin >> n;
        memset(used, false, sizeof(used));
        for (int i = 1; i <= n; i++)
        {
            ke[i].clear();
        }
        int cnt = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            ke[y].pb(x);
            cnt++;
        }
        int dem = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                DFS(i);
                dem++;
            }
        }
        if (dem == 1 && cnt == n - 1)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}