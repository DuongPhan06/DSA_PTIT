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
        map<char, int> mp;
        string s;
        cin >> s;
        for (char x : s)
        {
            mp[x]++;
        }
        int gtln = 0;
        int n;
        for (auto x : mp)
        {
            gtln = max(gtln, x.se);
        }
        if (gtln <= s.size() - gtln + 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}