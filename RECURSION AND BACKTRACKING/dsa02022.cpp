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

int a[2] = {0, 2};
vector<string> v;
void Try(int i, int bd, string t)
{
    if (t.size() == 8)
    {
        t.insert(2, "/");
        t.insert(5, "/");
        if (t[6] != '0' && t[4] != '0' && t[3] != '2')
        {
            if (t[0] == '2' && t[1] == '0')
            {
                v.pb(t);
            }
            else if (t[0] == '0' && t[1] == '2')
            {
                v.pb(t);
            }
            else if (t[0] == '2' && t[1] == '2')
            {
                v.pb(t);
            }
        }
        return;
    }
    for (int j = 0; j < 2; j++)
    {
        Try(i + 1, j, t + to_string(a[j]));
    }
}
int main()
{
    Try(0, 0, "");
    sort(v.begin(), v.end());
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}