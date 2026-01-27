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
int a[1000001];
vector<vector<int>> f;
void Try(int i)
{
    vector<int> v;
    if (i == 0)
    {
        return;
    }
    for (int j = 1; j <= i; j++)
    {
        v.pb(a[j]);
    }
    f.pb(v);
    for (int j = 0; j < i; j++)
    {
        a[j] += a[j + 1];
    }
    Try(i - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        f.clear();
        Try(n);
        for (int i = n - 1; i >= 0; i--)
        {
            cout << "[";
            for (int j = 0; j < n - i; j++)
            {
                cout << f[i][j];
                if (j < f[i].size() - 1)
                {
                    cout << " ";
                }
            }
            cout << "] ";
        }
        cout << endl;
    }
    return 0;
}