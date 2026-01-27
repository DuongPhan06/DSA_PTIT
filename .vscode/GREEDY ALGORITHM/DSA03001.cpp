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
    vector<int> v = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    while (t--)
    {
        int n;
        cin >> n;
        ll cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            cnt += n / v[i];
            n %= v[i];
        }
        cout << cnt << endl;
    }
    return 0;
}