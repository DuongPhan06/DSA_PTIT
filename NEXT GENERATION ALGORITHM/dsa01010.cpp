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
int b[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        int i = k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        int j = 1;
        while (i >= 1 && a[i] == n - j + 1)
        {
            i--;
            j++;
        }
        if (i == 0)
        {
            cout << k << endl;
        }
        else
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1] + 1;
            }
            for (int i = 1; i <= k; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    if (b[j] == a[i])
                    {
                        cnt++;
                    }
                }
            }
            cout << k - cnt << endl;
        }
    }
    return 0;
}