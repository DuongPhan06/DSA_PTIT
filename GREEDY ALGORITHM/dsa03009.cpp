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

bool used[1001];
struct inf
{
    int id, deadline, profit;
};

bool cmp(struct inf a, struct inf b)
{
    return a.profit > b.profit;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(used, false, sizeof(used));
        int n;
        cin >> n;
        struct inf a[1001];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].id >> a[i].deadline >> a[i].profit;
        }
        sort(a, a + n, cmp);
        ll ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            while (used[a[i].deadline] == true && a[i].deadline > 0)
            {
                a[i].deadline--;
            }
            if (a[i].deadline > 0 && used[a[i].deadline] == false)
            {
                ans += a[i].profit;
                cnt++;
                used[a[i].deadline] = true;
            }
        }
        cout << cnt << " " << ans << endl;
    }
    return 0;
}