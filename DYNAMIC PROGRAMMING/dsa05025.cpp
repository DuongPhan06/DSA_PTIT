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

ll dp[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                dp[i] += dp[i - 1];
            }
            else if (i == 2)
            {
                dp[i] += dp[i - 1] + dp[i - 2];
            }
            else
            {
                dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}