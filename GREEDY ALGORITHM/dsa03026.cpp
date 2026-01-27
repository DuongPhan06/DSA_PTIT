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
    int s, d;
    cin >> d >> s;
    string ans, a;
    int tmp = s;
    if (9 * d < s || s <= 0)
    {
        cout << "-1 -1" << endl;
        return 0;
    }
    s--;
    for (int i = 0; i < d; i++)
    {
        if (s >= 9)
        {
            ans += "9";
            s -= 9;
        }
        else
        {

            ans += to_string(s);
            s = 0;
        }
    }
    reverse(ans.begin(), ans.end());
    ans[0] = ans[0] + 1;
    for (int i = 0; i < d; i++)
    {
        if (tmp >= 9)
        {
            a += "9";
            tmp -= 9;
        }
        else
        {

            a += to_string(tmp);
            tmp = 0;
        }
    }
    cout << ans << " " << a << endl;
    return 0;
}