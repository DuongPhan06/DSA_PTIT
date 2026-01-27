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
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll tmp1 = 1ll * a[0] * a[1];
    ll tmp2 = 1ll * a[n - 1] * a[n - 2];
    ll tmp3 = 1ll * a[0] * a[1] * a[n - 1];
    ll tmp4 = 1ll * a[n - 1] * a[n - 2] * a[n - 3];
    ll gtln = max({tmp1, tmp2, tmp3, tmp4});
    cout << gtln << endl;
    return 0;
}