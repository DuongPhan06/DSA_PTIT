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
        vector<int> a(n), x(n + 1), y(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        x[0] = a[0];
        y[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            x[i] = min(x[i - 1], a[i]); // Gia tri nho nhat tu 0 den a[i]
        }
        for (int i = n - 2; i >= 0; i--)
        {
            y[i] = max(y[i + 1], a[i]); // Gia tri lon nhat tu a[i] den a[n - 1]
        }
        int ans = 0;
        int i = 0, j = 0;
        int check = 0;
        while (i < n && j < n)
        {
            if (y[j] > x[i])
            {
                check = 1;
                ans = max(ans, j - i);
                j++;
            }
            else
            {
                i++;
                j = i;
            }
        }
        if (ans)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}