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

int k, n, m;
char a[1001][1001];
bool visited[1001][1001];
vector<string> v;
vector<string> res;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Try(int i, int j, string t)
{
    for (string x : v)
    {
        if (x == t)
        {
            res.pb(x);
        }
    }
    for (int it = 0; it < 8; it++)
    {
        int i1 = i + dx[it];
        int j1 = j + dy[it];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1])
        {
            visited[i1][j1] = true;
            Try(i1, j1, t + a[i1][j1]);
            visited[i1][j1] = false;
        }
    }
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k >> n >> m;
        v.clear();
        res.clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            v.pb(s);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                memset(visited, false, sizeof(visited));
                visited[i][j] = true;
                string s = "";
                Try(i, j, s + a[i][j]);
            }
        }
        if (res.size() == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (string x : res)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}