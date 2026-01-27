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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<ll> q;
        q.push(9);
        while (true)
        {
            ll x = q.front();
            if (x % n == 0)
            {
                cout << x << endl;
                break;
            }
            q.pop();
            ll tmp1 = x * 10;
            ll tmp2 = x * 10 + 9;
            if (tmp1 % n == 0)
            {
                cout << tmp1 << endl;
                break;
            }
            else
            {
                q.push(tmp1);
            }
            if (tmp2 % n == 0)
            {
                cout << tmp2 << endl;
                break;
            }
            else
            {
                q.push(tmp2);
            }
        }
    }
    return 0;
}