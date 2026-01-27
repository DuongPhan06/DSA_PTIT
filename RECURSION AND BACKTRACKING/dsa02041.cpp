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
int x[1001];
int gtnn;

void Try(int n, int cnt)
{
    if (cnt > gtnn)
    {
        return;
    }
    if (n == 1)
    {
        gtnn = min(gtnn, cnt);
        return;
    }
    if (n % 2 == 0)
    {
        Try(n / 2, cnt + 1);
    }
    if (n % 3 == 0)
    {
        Try(n / 3, cnt + 1);
    }
    Try(n - 1, cnt + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        gtnn = INT_MAX;
        Try(n, 0);
        cout << gtnn << endl;
    }
    return 0;
}