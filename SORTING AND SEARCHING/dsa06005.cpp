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
        set<int> se, se1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            se.insert(a[i]);
            se1.insert(a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            se.insert(b[i]);
        }
        for (auto x : se)
        {
            cout << x << " ";
        }
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            if (se1.count(b[i]))
            {
                cout << b[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}