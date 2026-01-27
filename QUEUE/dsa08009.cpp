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

bool visited[100001];
void solve()
{
    int s, t;
    cin >> s >> t;
    int gtnn = 1e9;
    memset(visited, false, sizeof(visited));
    if (s > t)
    {
        cout << s - t << endl;
        return;
    }
    else if (s == t)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        queue<pair<int, int>> q;
        int cnt = 0;
        q.push({s, cnt});
        visited[s] = true;
        while (!q.empty())
        {
            pair<int, int> x = q.front();
            q.pop();
            int h = x.fi, steps = x.se;
            if (h == t)
            {
                gtnn = min(gtnn, steps);
            }
            int x1 = x.fi * 2, x2 = x.fi - 1;
            if (visited[x1] == false && x1 <= 10000 && x1 >= 0)
            {
                visited[x1] = true;
                q.push({x1, steps + 1});
            }
            if (visited[x2] == false && x2 <= 10000 && x2 >= 0)
            {
                visited[x2] = true;
                q.push({x2, steps + 1});
            }
        }
        cout << gtnn << endl;
    }
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