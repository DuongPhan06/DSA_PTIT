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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + m);
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                cout << a[i] << " ";
                i++;
            }
            else if (a[i] > b[j])
            {
                cout << b[j] << " ";
                j++;
            }
            else
            {
                cout << a[i] << " " << b[j] << " ";
                i++;
                j++;
            }
        }
        while (i < n)
        {
            cout << a[i] << " ";
            i++;
        }
        while (j < m)
        {
            cout << b[j] << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}