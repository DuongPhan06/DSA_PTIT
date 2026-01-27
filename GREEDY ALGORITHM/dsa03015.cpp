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
        int n, s, m;
        cin >> n >> s >> m;
        ll total = 1ll * s * m;
        s = s - s / 7;
        int i = 1;
        bool check = true;
        ll target = 0;
        if (total > s * n)
        {
            check = false;
        }
        int day;
        for (int i = 1; i <= s; i++)
        {
            target += n;
            if (target >= total)
            {
                day = i;
                break;
            }
        }
        if (check == true)
        {
            cout << day << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}