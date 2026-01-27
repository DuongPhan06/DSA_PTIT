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

int a[1000001];
int n, x[1001], k;
void Try(int i, int bd)
{
    for (int j = bd; j <= n; j++)
    {
        if (a[j] != a[j - 1])
        {
            x[i] = j;
            if (i == k)
            {
                for (int i = 1; i <= k; i++)
                {
                    cout << a[x[i]] << " ";
                }
                cout << endl;
            }
            else
            {
                Try(i + 1, j + 1);
            }
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
    sort(a + 1, a + n + 1);
    Try(1, 1);
    return 0;
}