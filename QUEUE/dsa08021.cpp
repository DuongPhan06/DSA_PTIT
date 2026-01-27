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

int a[1001][1001];
int dp[10001][1001];
bool used[1001][1001];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    memset(used, false, sizeof(used));
    queue<pair<int, int>> q;
    q.push({1, 1});
    dp[1][1] = 0;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        int i = x.fi, j = x.se;
        if (i == n && j == m)
        {
            cout << dp[i][j] << endl;
            return;
        }
        int i1 = i + a[i][j];
        if (used[i1][j] == false && i1 >= 1 && i1 <= n)
        {
            used[i1][j] = true;
            q.push({i1, j});
            dp[i1][j] = dp[i][j] + 1;
        }
        int j1 = j + a[i][j];
        if (used[i][j1] == false && j1 >= 1 && j1 <= m)
        {
            used[i][j1] = true;
            q.push({i, j1});
            dp[i][j1] = dp[i][j] + 1;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}