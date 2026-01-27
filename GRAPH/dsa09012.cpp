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
// Bài toán tìm đỉnh trụ, cạnh cầu
// Cạnh cầu: low[v] > disc[u] (nghiêm ngặt hơn)
// Đỉnh trụ: low[v] >= disc[u] (bao gồm cả trường hợp bằng)
// disc[u] = Thời điểm bắt đầu khám phá đỉnh u trong DFS
// low[u] = Thời gian khám phá NHỎ NHẤT trong số các đỉnh mà từ u có thể đến được

int n, m, timer;
vector<int> ke[1005];
bool visited[1001];
int AP[1001];
int disc[1001], low[1001];
void DFS(int u, int par)
{
    timer++;
    disc[u] = low[u] = timer;
    visited[u] = true;
    int cnt = 0;
    for (int v : ke[u])
    {
        if (v == par)
        {
            continue;
        }
        if (!visited[v])
        {
            cnt++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (par != -1 && low[v] >= disc[u])
            {
                AP[u] = 1;
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (par == -1 && cnt > 1)
    {
        AP[u] = 1; // Trg hop xoa dinh tru thi co 2 dinh con moi lien thong
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        timer = 0;
        memset(visited, false, sizeof(visited));
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        memset(AP, 0, sizeof(AP));
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
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                DFS(i, -1);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (AP[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}