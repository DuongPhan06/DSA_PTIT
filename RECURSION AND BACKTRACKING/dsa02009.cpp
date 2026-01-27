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

int a[1001];
int x[101];
int used[101];
int n, k;
ll f;
int check;
void Try(int i, int bd, ll sum, int cnt)
{
    if (check)
    {
        return;
    }
    if (sum > f)
    {
        return;
    }
    if (cnt == k)
    {
        check = 1;
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        if (used[j] == 0 && sum + a[j] <= f)
        {
            used[j] = 1;
            x[i] = j;
            if (sum + a[j] == f)
            {
                Try(i + 1, 1, 0, cnt + 1);
            }
            else
            {
                Try(i + 1, j + 1, sum + a[j], cnt);
            }
            used[j] = 0;
        }
    }
}
int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        memset(used, 0, sizeof(used));
        check = 0;
        cin >> n >> k;
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if (s % k == 0)
        {
            f = s / k;
            Try(1, 1, 0, 0);
            cout << check << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}