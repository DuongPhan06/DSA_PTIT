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

int a[1000001];
int c[1000001];
int dp[1001][1001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        int n, v;
        cin >> n >> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i]; // the tich
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i]; // gia tri
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]);
                }
            }
        }
        cout << dp[n][v] << endl;
    }
    return 0;
}