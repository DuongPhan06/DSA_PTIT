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

int cnt[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = a[0]; i <= a.back(); i++)
        {
            if (!cnt[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}