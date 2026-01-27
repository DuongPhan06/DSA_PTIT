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
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();
        a = "@" + a;
        b = "@" + b;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (a[i] == b[j])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}