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
// solution: k <= a[i] / b[i] < k + 1 => b[i] > a[i] / (k + 1)
// => b[i] >= (a[i] / (k + 1)) + 1 => k(min) = (a[i] / (k + 1)) + 1
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> b;
    ll max_val = *max_element(a, a + n); // k co the chay den max_val
    for (int i = 0; i <= max_val; i++)
    {
        vector<ll> v;
        for (int j = 0; j < n; j++)
        {
            ll tmp = a[j] / (i + 1) + 1;
            if (a[j] / tmp == i)
            {
                v.pb(tmp);
            }
        }
        if (v.size() == n)
        {
            b.pb(v);
        }
    }
    ll gtnn = INT_MAX;
    for (int i = 0; i < b.size(); i++)
    {
        ll res = 0;
        for (int x : b[i])
        {
            res += x;
        }
        gtnn = min(gtnn, res);
    }
    cout << gtnn << endl;
    return 0;
}