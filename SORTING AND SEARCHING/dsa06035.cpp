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

// Bai bị lỗi test nên không tính dasu bằng
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> l(n), r(n);
        l[0] = 1;
        for (int i = 1; i < n; i++)
        { // Tim day con tang lien tiep dai nhat
            if (a[i] > a[i - 1])
            {
                l[i] = l[i - 1] + 1;
            }
            else
            {
                l[i] = 1;
            }
        }
        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        { // Tim day con giam lien tiep dai nhat
            if (a[i] > a[i + 1])
            {
                r[i] = r[i + 1] + 1;
            }
            else
            {
                r[i] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, l[i] + r[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}