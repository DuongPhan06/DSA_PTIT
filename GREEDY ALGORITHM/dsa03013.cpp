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
        int n;
        string s;
        cin >> n >> s;
        int gtln = 0;
        map<char, int> mp;
        for (char x : s)
        {
            mp[x]++;
        }
        for (auto x : mp)
        {
            gtln = max(gtln, x.se);
        }
        int kt = s.size() - gtln;
        int k = (n - 1) * (gtln - 1); // so ki tu toi thieu
        if (k <= kt)
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