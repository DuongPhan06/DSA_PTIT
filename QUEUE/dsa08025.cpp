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

int dp[1001][1001];
bool visited[1001][1001];
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    dp[x][y] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int a = top.fi, b = top.se;
        for (int i = 0; i < 8; i++)
        {
            int a1 = a + dx[i];
            int b1 = b + dy[i];
            if (a1 >= 1 && a1 <= 8 && b1 >= 1 && b1 <= 8 && !visited[a1][b1])
            {
                visited[a1][b1] = true;
                q.push({a1, b1});
                dp[a1][b1] = dp[a][b] + 1;
            }
        }
    }
}
void solve()
{
    string a, b;
    cin >> a >> b;
    memset(visited, false, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    int x1 = a[0] - 'a' + 1;
    int y1 = a[1] - '0';
    int x2 = b[0] - 'a' + 1;
    int y2 = b[1] - '0';
    BFS(x1, y1);
    cout << dp[x2][y2] << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}