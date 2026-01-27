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

bool check1(int n)
{
    set<int> se;
    while (n != 0)
    {
        int du = n % 10;
        if (se.find(du) == se.end())
        {
            se.insert(du);
        }
        else
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool check2(int n)
{
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > '5')
        {
            return false;
        }
    }
    return true;
}

void xuly()
{
    dp[0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        if (check1(i) && check2(i))
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
}

void solve()
{
    xuly();
    int l, r;
    cin >> l >> r;
    if (l == 0)
    {
        cout << dp[r];
    }
    else
    {
        cout << dp[r] - dp[l - 1] << endl;
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