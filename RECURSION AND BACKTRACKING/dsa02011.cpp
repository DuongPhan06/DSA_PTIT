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

int n, k;
int a[1000001], x[1001];
int gtnn = INT_MAX;
void Try(int i, int bd, ll sum, int cnt)
{
    if (cnt >= gtnn)
    {
        return;
    }
    if (sum == k)
    {
        gtnn = min(gtnn, cnt);
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        x[i] = j;
        Try(i + 1, j + 1, sum + a[j], cnt + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        gtnn = INT_MAX;
        Try(1, 1, 0, 0);
        if (gtnn == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << gtnn << endl;
        }
    }
    return 0;
}