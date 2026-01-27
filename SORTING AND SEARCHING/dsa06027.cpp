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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> v;
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[i])
                {
                    swap(a[i], a[j]);
                }
            }
            string t;
            t = t + "Buoc " + to_string(i + 1) + ": ";
            for (int i = 0; i < n; i++)
            {
                t = t + to_string(a[i]) + " ";
            }
            v.pb(t);
        }
        reverse(v.begin(), v.end());
        for (string x : v)
        {
            cout << x << endl;
        }
    }
    return 0;
}
