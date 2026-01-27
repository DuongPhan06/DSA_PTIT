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

int n;
int a[101];
int check;
ll sum;

void Try(int i, int bd, ll s)
{
    if (check)
    {
        return;
    }
    if (s == sum)
    {
        check = 1;
        return;
    }
    if (s > sum)
    {
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        Try(i + 1, j + 1, s + a[j]);
    }
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll total = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            total += a[i];
        }
        if (total % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        sum = total / 2;
        sort(a + 1, a + n + 1, greater<int>());
        check = 0;
        Try(1, 1, 0);
        if (check)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}