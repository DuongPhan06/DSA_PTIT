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

int a[1000001];
ll dp1[1000001];
ll dp2[1000001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp1[i] = a[i];
        }
        else
        {
            dp1[i] = dp1[i - 1] + a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp2[i] = abs(a[i]);
        }
        else
        {
            dp2[i] = dp2[i - 1] + abs(a[i]);
        }
    }
    ll gtln = -1e9 - 5;
    for (int i = 0; i < n; i++)
    {
        gtln = max(gtln, dp1[i] + dp2[i]);
    }
    cout << gtln << endl;
    return 0;
}