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
int check = 0;
void Try(int i, int bd, ll sum)
{
    if (sum > k)
    {
        return;
    }
    if (sum == k)
    {
        check = 1;
        cout << "[";
        for (int f = 1; f < i; f++)
        {
            cout << a[x[f]];
            if (f != i - 1)
            {
                cout << " ";
            }
        }
        cout << "]";
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        if (sum + a[j] <= k)
        {
            x[i] = j;
            Try(i + 1, j, sum + a[j]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        check = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (!check)
        {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}