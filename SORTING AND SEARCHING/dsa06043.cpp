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

int dp[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i] = a[i];
            }
            else
            {
                dp[i] = dp[i - 1] + a[i];
            }
        }
        int l = 0, r = n - 1;
        int check = 0;
        ll x, y;
        while (l < n)
        {

            x = dp[l - 1];
            y = dp[r] - dp[l];
            if (x == y)
            {
                check = 1;
                break;
            }
            l++;
        }
        if (check)
        {
            cout << l + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}