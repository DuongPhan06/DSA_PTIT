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
int cnt[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        int i = k;
        int tmp = k;
        while (i >= 1 && a[i] == a[i - 1] + 1)
        {
            i--;
        }
        if (i == 0)
        {
            for (int i = n - k + 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            a[i]--;
            for (int j = k; j >= i + 1; j--)
            {
                a[j] = n;
                n--;
            }
            for (int i = 1; i <= k; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}