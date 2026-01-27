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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
            string tmp;
            for (int i = 0; i < n; i++)
            {
                tmp = tmp + to_string(a[i]) + " ";
            }
            if (v.empty())
            {
                v.pb(tmp);
            }
            else
            {
                if (v.back() != tmp)
                {
                    v.pb(tmp);
                }
            }
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << "Buoc " << v.size() - i << ": ";
            cout << v[i] << endl;
        }
    }
    return 0;
}