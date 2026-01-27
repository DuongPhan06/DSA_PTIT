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

vector<string> v;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
        string t;
        for (int i = 0; i < n; i++)
        {
            t = t + to_string(a[i]) + " ";
        }
        if (v.empty())
        {
            v.pb(t);
        }
        else
        {
            if (v.back() != t)
            {
                v.pb(t);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Buoc " << i + 1 << ": ";
        cout << v[i] << endl;
    }
    return 0;
}