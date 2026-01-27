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

void solve(int n)
{
    for (int b = n / 7; b >= 0; b--)
    {
        ll remain = n - 7 * b;
        if (remain % 4 == 0)
        {
            int a = remain / 4;
            cout << string(a, '4');
            cout << string(b, '7');
            return;
        }
    }
    cout << -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
        cout << endl;
        // int d7 = 0, d4 = 0;
        // bool check = true;
        // while (n > 0)
        // {
        //     if (n % 7 == 0)
        //     {
        //         d7++;
        //         n -= 7;
        //     }
        //     else if (n % 4 == 0)
        //     {
        //         d4++;
        //         n -= 4;
        //     }
        //     else
        //     {
        //         n -= 4;
        //         d4++;
        //     }
        // }
        // if (n < 0)
        // {
        //     check = false;
        // }
        // if (check)
        // {
        //     for (int i = 0; i < d4; i++)
        //     {
        //         cout << 4;
        //     }
        //     for (int i = 0; i < d7; i++)
        //     {
        //         cout << 7;
        //     }
        // }
        // else
        // {
        //     cout << -1 << endl;
        // }
        // cout << endl;
    }
    return 0;
}