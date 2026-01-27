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

int x[1001];
string s;
ll res = 0;

bool check(ll n)
{
    ll k = cbrt(n) + 0.5;
    return k * k * k == n;
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == s.size() - 1)
        {
            ll tmp = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (x[i])
                {
                    tmp = tmp * 10 + s[i] - '0';
                }
            }
            if (check(tmp))
            {
                if (tmp > res)
                {
                    res = tmp;
                }
            }
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        res = 0;
        cin >> s;
        Try(0);
        if (res == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << res << endl;
        }
    }
    return 0;
}