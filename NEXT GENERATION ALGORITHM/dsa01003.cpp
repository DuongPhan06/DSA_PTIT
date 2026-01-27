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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int check = 1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int i = n - 1;
        while (i >= 1 && a[i] >= a[i + 1])
        {
            i--;
        }
        if (i == 0)
        {
            check = 0;
        }
        if (!check)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            int j = i + 1;
            while (j <= n && a[j] <= a[i])
            {
                j--;
            }
            swap(a[i], a[j]);
            sort(a + i + 1, a + n + 1);
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}