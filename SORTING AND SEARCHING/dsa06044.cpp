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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c, l;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i % 2 == 0)
        {
            c.pb(a[i]);
        }
        else
        {
            l.pb(a[i]);
        }
    }
    sort(c.begin(), c.end(), greater<int>());
    sort(l.begin(), l.end());
    int i_c = 0, i_l = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            cout << c[i_c] << " ";
            i_c++;
        }
        else
        {
            cout << l[i_l] << " ";
            i_l++;
        }
    }
    return 0;
}