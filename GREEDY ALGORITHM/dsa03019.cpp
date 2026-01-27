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

void Try(ll tu, ll mau)
{
    if (mau % tu == 0)
    {
        cout << 1 << "/" << mau / tu;
        return;
    }
    ll x = mau / tu + 1;
    cout << 1 << "/" << x << " + ";
    ll tumoi = tu * x - mau;
    ll maumoi = mau * x;
    Try(tumoi, maumoi);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll p, q;
        cin >> p >> q;
        Try(p, q);
        cout << endl;
    }
    return 0;
}