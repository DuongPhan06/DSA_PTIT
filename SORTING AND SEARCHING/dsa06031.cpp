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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        multiset<int> se;
        for (int i = 0; i < k; i++)
        {
            se.insert(a[i]);
        }
        cout << *se.rbegin() << " ";
        for (int i = k; i < n; i++)
        {
            auto it = se.find(a[i - k]);
            se.erase(it);
            se.insert(a[i]);
            cout << *se.rbegin() << " ";
        }
        cout << endl;
    }
    return 0;
}