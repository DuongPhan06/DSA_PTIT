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
int a[1000001];
int x[1001];
ll s = 0;
int t, tmp;
int res = 0;
vector<ll> v;
void Try(int i, int tmp, int sum, int cnt)
{
    if (i > n + 1)
    {
        return;
    }
    if (cnt == k && i == n + 1)
    {
        res++;
        return;
    }
    for (int j = i; j <= n; j++)
    {
        sum += a[j];
        if (sum == tmp)
        {
            Try(j + 1, tmp, 0, cnt + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % k == 0)
    {
        tmp = s / k;
        Try(1, tmp, 0, 0);
        cout << res << endl;
    }
    else
    {
        cout << 0;
    }
    return 0;
}