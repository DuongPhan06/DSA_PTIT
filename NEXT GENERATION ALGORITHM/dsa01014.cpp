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

int x[1001];
int cnt = 0;
int n, k, s;
void Try(int i, int bd, ll sum)
{
    if (i > k + 1 || sum > s)
    {
        return;
    }
    if (i == k + 1)
    {
        if (sum == s)
        {
            cnt++;
            return;
        }
        else
        {
            return;
        }
    }
    for (int j = bd; j <= n; j++)
    {
        x[i] = j;
        Try(i + 1, j + 1, sum + j);
    }
}
int main()
{
    faster;
    while (true)
    {
        cnt = 0;
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0)
        {
            break;
        }
        Try(1, 1, 0);
        cout << cnt << endl;
    }
    return 0;
}