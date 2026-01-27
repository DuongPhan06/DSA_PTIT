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

int n, m;
int a[1001][1001];
int b[1001][1001];
int check = 0;
int x[1001];
int cnt = 0;
void Try(int i, int j)
{
    if (i == n && j == m)
    {
        cnt++;
        return;
    }
    if (i + 1 <= n && j <= m)
    {
        Try(i + 1, j);
    }
    if (i <= n && j + 1 <= m)
    {
        Try(i, j + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        check = 0;
        cnt = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        Try(1, 1);
        cout << cnt << endl;
    }
    return 0;
}