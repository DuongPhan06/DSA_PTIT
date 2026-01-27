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

bool check(ll n)
{
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0' || s[i] != '1')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<ll> q;
        q.push(1);
        while (!q.empty())
        {
            ll x = q.front();
            q.pop();
            if (x % n == 0)
            {
                cout << x << endl;
                break;
            }
            else
            {
                q.push(x * 10);
                q.push(x * 10 + 1);
            }
        }
    }
    return 0;
}