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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n + 5), b(m + 5), c(k + 5);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> c[i];
        }
        int i = 0, j = 0, l = 0;
        vector<int> kq;
        while (i < n && j < m && l < k)
        {
            if (a[i] == b[j] && b[j] == c[l])
            {
                kq.pb(a[i]);
                i++;
                j++;
                l++;
            }
            if (a[i] < b[j])
            {
                i++;
            }
            else if (b[j] < c[l])
            {
                j++;
            }
            else if (c[l] < a[i])
            {
                l++;
            }
        }
        if (kq.size() > 0)
        {
            for (int x : kq)
            {
                cout << x << " ";
            }
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}