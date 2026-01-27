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
int cnt = 0;
void Try(int i, int bd)
{
    if (i > n + 1)
    {
        return;
    }
    if (i == k + 1)
    {
        cnt++;
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        if (i == 1 || a[j] >= a[x[i - 1]])
        {
            x[i] = j;
            Try(i + 1, j + 1);
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1, 1);
    cout << cnt << endl;
    return 0;
}